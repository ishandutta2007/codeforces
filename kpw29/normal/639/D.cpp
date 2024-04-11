#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const int MAXN = 1e6 + 9;

bitset <MAXN> odw;
vector < pair<long long, int> > vec;
long long tab[MAXN];
long long wartosc[MAXN];

int main()
{
    int n;
    long long wyn = INF * INF * 3ll, b, c, tmp, tmp2, sum, ost, akt, k, mini;
    int wsk;
    
    cin>>n>>k>>b>>c;
    
    for(int i = 0; i < n; i++)
      {
          scanf("%lld", &tab[i]);
      }
    
    if(5 * c < b)
      b = 5 * c;
    
    sort(tab, tab + n);
    reverse(tab, tab + n);
    
    //int reszta = 1;
    for(long long reszta = 0; reszta < 5; reszta++)
      {
          odw.reset();
          vec.clear();
          sum = 0;
          ost = INF + reszta;
          //ost = 20 + reszta;
          
          for(int i = 0; i < n; i++)
            {
                tmp2 = tab[i];
                tmp2 += 5ll * INF;
                tmp = 0;
                
                while(tmp2 % 5 != reszta)
                  {
                      tmp++;
                      tmp2++;
                  }
                
                //tmp2 = 20 + reszta;
                tmp2 = INF + reszta;
                
                wartosc[i] = (((tmp2 - tab[i]) / 5ll) * b) + (tmp * c);
                
            //    cerr<<"WARTOCS "<<reszta<<" "<<i<<" "<<tab[i]<<" "<<wartosc[i]<<endl;
                vec.push_back(make_pair(wartosc[i], i));
            }
          
          sort(vec.begin(), vec.end());
          
          for(int i = 0; i < k; i++)
            {
                sum += vec[i].first;
            }
          
          wsk = k - 1;
          mini = wartosc[vec[wsk].second];
          
          wyn = min(wyn, sum);
          
        //  cerr<<reszta<<" "<<wyn<<endl;
          
          for(int i = 0; i < n; i++)
            {
                akt = tab[i];
                
                while((akt + (5ll * INF)) % 5ll != reszta)
                  akt++;
                
             //   cerr<<reszta<<" "<<i<<" "<<akt<<" "<<sum<<endl;
                
                if(akt < ost)
                  {
                      tmp = sum;
                      tmp -= k * ((tmp2 - akt) / 5ll) * b;
                      
                    //  cerr<<reszta<<" reszta "<<tmp<<endl;
                      wyn = min(tmp, wyn);
                      
                      ost = akt;
                  }
                
                if(mini >= wartosc[i])
                  {
                      odw[i] = true;
                      sum -= wartosc[i];
                      wsk++;
                      
                      while((wsk < n) && (odw[vec[wsk].second]))
                        {
                            wsk++;
                        }
                      
                      if(wsk == n)
                        break;
                      
                      mini = vec[wsk].first;
                      sum += mini;
                  }
                
                else
                  {
                      odw[i] = true;
                  }
            }
      }
    
    cout<<wyn<<endl;
    
    return 0;
}