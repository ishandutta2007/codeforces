#include <bits/stdc++.h>
using namespace std;
int test, n, a[222222], pos, cnt[222222], nw, crt, pp;
bool u[222222];
vector<int> ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n + 1; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) cnt[a[i]] ++;
		ans.clear(); nw = 0;
		while(cnt[nw]) nw++;
		pos = 1;
		while(pos <= n)
		{
			ans.push_back(nw);
			if (nw == 0)
			{
				pos++;
				continue;
			}
			for (int j = 0; j < nw; j++) u[j] = 0;
			crt = 0; pp = nw;
			while(pos <= n && crt < nw)
			{
				if (!u[a[pos]]) 
				{
					u[a[pos]] = 1;
					if (a[pos] < nw) crt++;
				}
				cnt[a[pos]] --;
				if (!cnt[a[pos]]) pp = min(pp, a[pos]);
				pos++;
			}
			nw = pp;
			//cout << pos << " " << nw << endl;
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}