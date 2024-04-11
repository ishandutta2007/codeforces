#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 9;

int tab[MAXN];
int ile[MAXN];

int main()
{
    int n, maxi = 0, a;
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
      {
          scanf("%d", &tab[i]);
          
          ile[tab[i]]++;
          maxi = max(ile[tab[i]], maxi);
      }
    
    fill(ile, ile + MAXN, 0);
    
    for(int i = 0; i < n; i++)
      {
          a = tab[i];
          ile[a]++;
          
          if(maxi == ile[a])
            {
                cout<<a<<endl;
                break;
            }
      }
    
    return 0;
}