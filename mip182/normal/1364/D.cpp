#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
//map <int, int> c2;
vector <pair <int, int>> c1;
vector <int> used(100005);
vector <vector <int>> g(100005);
vector <int> preva(100005, -1);
vector <int> color(100005);
deque <int> cycle;
vector <int> num(2, 0);
vector <bool> ex(100005, false);

void dfs(int start, bool &c, vector <vector <int>> &g)
{
    
        used[start]=1;
    for(auto u: g[start])
    {
        if(!c)
        {
      if(used[u]==0)
      {
          preva[u]=start;
          color[u]=1-color[start];
          num[color[u]]++;
          dfs(u, c, g);
      }
      if((used[u]==1) && (u != preva[start]))
      {
          int a=start;
          int number=0;
          while (a != u)
          {
              cycle.push_back(a);
              ex[a]=true;
              number++;
              a=preva[a];
          }
          cycle.push_back(u);
          ex[u]=true;
          c=1;
          
          // 
      }
        }
    }
    used[start]=2;
    

};
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio (false);
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, int>> e;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        e.push_back(make_pair(a-1, b-1));
    }

    color[0]=0;
    num[0]=1;
    bool c=0;
    dfs(0, c, g);
    if(cycle.empty())
    {
        cout << 1 << endl;
        if(num[0]>=(k+1)/2)
        {
            int r=0, rr=0;
            while(r<=(k+1)/2)
            {
                if(color[rr]==0)
                {
                    cout << rr+1 << " ";
                    r++;
                }
                rr++;
                if(r == (k+1)/2) break;
    
            }
        }
        else
        {
            int s=0, ss=0;
            while(s<=(k+1)/2)
            {
                if(color[ss]==1)
                {
                    cout << ss+1 << " ";
                    s++;
                }
                ss++;
                if(s == (k+1)/2) break;
        
            }
        };
    }
    else
    {
    preva[0]=cycle[0];
    for(auto u: e)
    {
        if((ex[u.first]) && (ex[u.second]) && (u.second != preva[u.first]) && (u.first != preva[u.second]))
                {
                    while (cycle.front()!=u.first && cycle.front()!=u.second)
                    {
                        ex[cycle.front()]=0;
                        cycle.pop_front();
                    }
                    while (cycle.back()!=u.first && cycle.back()!=u.second)
                    {
                        ex[cycle.back()]=0;
                        cycle.pop_back();
                    }
                    if(ex[preva[u.first]]) preva[u.second]=u.first;
                    else preva[u.first]=u.second;
                }
            };
    

         if (cycle.size()<=k)
               {
                   cout << 2 << endl << cycle.size() << endl;
                   for (int i:cycle)
                   {
                       cout << i+1 << " ";
                   }
               }
               else
               {
                   cout << 1 << endl;
                   for (int i=0;i<(k+1)/2;i++)
                   {
                       cout << cycle[2*i]+1 << " ";
                   }
               }
    }
 
}