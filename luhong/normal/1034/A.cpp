#include <cstdio>
#include <cstring> 
#include <algorithm>
#include <iostream>

using namespace std;

bool is[15000010];
int pri[1500010], Min[15000010], tot = 0;
int id[15000010]; 
int cnt[1500010], s[1500010], mi[1500010];
void init()
{
    for(int i=2;i<=15000000;i++)
    {
        if(!is[i])pri[++tot]=i, Min[i] = i, id[i] = tot, mi[tot] = 1e9;
        for(int j=1;j<=tot&&i*pri[j]<=15000000;j++)
        {
            is[i*pri[j]]=1; Min[i * pri[j]] = pri[j];
            if(i%pri[j]==0){break;}
        }
    }
}
int main()
{
	init();
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		while(a != 1)
		{
			int lst = Min[a], t = 0;
			while(a != 1)
			{
				a /= Min[a];
				if(Min[a] != lst) break;
				t++;
			}
			cnt[id[lst]]++;
			if(t < mi[id[lst]]) mi[id[lst]] = t, s[id[lst]] = 1;
			else if(t == mi[id[lst]]) s[id[lst]]++;
		}
	}
	int ans = n;
	for(int i = 1; i <= tot; i++)
	{
		if(cnt[i] == 0) continue;
		else if(cnt[i] == n)
		{
			if(s[i] == n) continue;
			else ans = std::min(ans, s[i]);
		}
		else ans = std::min(ans, n - cnt[i]);
	}
	if(ans != n) printf("%d\n", ans);
	else puts("-1");
	return 0;
}