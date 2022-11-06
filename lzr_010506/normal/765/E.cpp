#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define vi vector<int>
#define ii pair<int, int>
int n;
vi g[200010];
bool vis[200010];

int deg[200010];
set<int> st[200010];
int main()
{
    cin >> n;
    for(int i = 0; i < n - 1; i ++)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<ii> q;
    for(int i = 0; i < n; i ++)
    {
        deg[i+1] = g[i+1].size();
        if(g[i+1].size() == 1) q.push(mp(i+1,0));
	}
    int last  = -1;
    int c = 0 ;
    while(q.size())
    {
        c ++ ;
        int p = q.front().first , x = q.front().second;
        q.pop();
        last = p;
        vis[p]=1;
   		for(int i = 0; i < g[p].size(); i ++)deg[g[p][i]] --;
        for(int i = 0; i < g[p].size(); i ++)
        {
            int fa = g[p][i];
            if(!vis[fa])
            {
                st[fa].insert(x + 1);
                if(deg[fa] == 1 && st[fa].size() == 1)
                    q.push(mp(fa, x + 1));
            }
    	}
    }

    if(c < n - 1) cout<<"-1";
    else
    {
        if(c == n - 1)
        	for(int i = 0; i < n; i ++)
        		if(!vis[i + 1])
        			last = i + 1;
        if(st[last].size() > 2)
        {
            cout << -1;
            return 0;
        }
        int x = 0 ;
        for(set<int>::iterator it = st[last].begin(); it != st[last].end(); it ++) x += *it ;
        while(x % 2 == 0) x >>= 1;
        cout << x;
    }

    return 0 ;
}