#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 9;

bool czy[MAXN];
set <int> seti;
int tab[MAXN];

int main()
{
    int n, k, q, a, t, maxi;
    
    cin>>n>>k>>q;
    
    for(int i = 0; i < n; i++)
      {
          scanf("%d", &tab[i]);
      }
    
    for(int i = 0; i < q; i++)
      {
          scanf("%d %d", &t, &a);
          
          a--;
          
          if(t == 1)
            {
                seti.insert(tab[a]);
                czy[a] = true;
            }
          
          else
            {
                if((seti.empty()) || (!czy[a]))
                  {
                      puts("NO");
                      continue;
                  }
                
                auto it = seti.end();
                it--;
                
                for(int j = 0; j < k; j++)
                  {
                      maxi = *it;
                      
                      if(it == seti.begin())
                        break;
                      
                      it--;
                  }
                
                if(tab[a] >= maxi)
                  puts("YES");
                
                else
                  puts("NO");
            }
      }
    
    return 0;
}