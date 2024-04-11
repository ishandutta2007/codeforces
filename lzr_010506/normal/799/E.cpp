#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int c[N], stat[N];
vector<pair<int,int>> ds[10];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main() 
{
    int n, m, k;
    n = read();
    m = read();
    k = read();
    for (int i = 1; i <= n; i ++)
    	c[i] = read();
    for (int i = 0; i < 2; i ++) 
    {
        int sz = read();
        while (sz --) 
        {
            int x;
            scanf("%d", &x);
            stat[x] |= (1 << i);
        }
    }

    set<pair<int,int>> ss, Tp;
    LL sum = 0;

    for (int i = 1; i <= n; i ++) 
    {
        if (stat[i] == 0 || stat[i] == 3) 
        {
            Tp.insert({c[i],i});
            sum += c[i];
        }
        ds[stat[i]].push_back({c[i],i});
    }

    for (int i = 1; i <= 3; i ++) 
    	if (!ds[i].empty()) sort(ds[i].begin(), ds[i].end());

    LL ans = -1;
    LL vis[10];

    vis[1] = vis[2] = vis[3] = 0;

    for (int i = 1; i <= 2; i ++)
        for (auto &p : ds[i]) vis[i] += p.first;

    for (int i = 0; i <= ds[3].size(); i ++) 
    {
        if (i > 0) 
        {
            int id = ds[3][i-1].second;
            auto it = Tp.find({c[id],id});
            if (it != Tp.end())
            {
                Tp.erase(it);
                sum -= c[id];
            }
            else ss.erase({c[id],id});

            vis[3] += c[id];
        }

        if ((k-i)*2+i <= m && min(ds[1].size(),ds[2].size()) >= k-i) 
        {
            for (int j = 1; j <= 2; j++) 
                while (ds[j].size() > k-i) 
                {
                    int id = ds[j].back().second;
                    if (!Tp.empty() && c[id] < (-- Tp.end()) -> first) 
                    {
                        Tp.insert({c[id],id});
                        sum += c[id];
                    }
                    else ss.insert({c[id],id});
                    vis[j] -= c[id];
                    ds[j].pop_back();
                }

            int tmp = m - (k - i) * 2 - i;

            while (Tp.size() < tmp) 
            {
                int id = ss.begin()->second;
                Tp.insert({c[id],id});
                sum += c[id];
                ss.erase(ss.begin());
            }        

            while (Tp.size() > tmp) 
            {
                int id = (--Tp.end())->second;
                Tp.erase({c[id],id});
                sum -= c[id];
                ss.insert({c[id],id});
            }

            if (Tp.size() == tmp) 
            {
                LL res = vis[1] + vis[2] + vis[3] + sum;
                if (ans < 0 || ans > res) ans = res;
            }
        }
    }

    printf("%lld", ans);
}