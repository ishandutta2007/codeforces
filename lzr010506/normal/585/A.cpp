#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
ll v[N], d[N], p[N];

int main()
{
	scanf("%d",&n);
    for(int i = 1; i <= n; i ++)
		scanf("%I64d%I64d%I64d", v + i, d + i, p + i);
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
	{
        if(p[i] >= 0)
		{
            ans.push_back(i);
            ll j, dec = v[i], extra = 0;
            for(j = i + 1; dec && j <= n; j ++)
                if(p[j] >= 0)
				{
                    p[j] -= dec + extra;
                    if(p[j] < 0) extra += d[j];
                    dec --;
                }
            
            for(; extra && j <= n; j ++)
                if(p[j] >= 0) 
				{
                    p[j] -= extra;
                    if(p[j] < 0) extra += d[j];
                }
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}