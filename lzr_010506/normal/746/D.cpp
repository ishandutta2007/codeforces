#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int main()
{
	int n, k, a, b;
	bool flag;
	cin >> n >> k >> a >> b;
	if(a > b) flag = 1;
	else flag = 0;
	if(a < b) swap(a, b);
	if(b < n / (k + 1)) {printf("NO"); return 0;}
	int now = 0;

	for(int i = 1; i <= n; i ++)
	{
		if(a <= b)
		{
			bool F = 0;
			if(ans[i - 1] == 1) F = 1;
			while(i <= n)
				if(F == 0) ans[i] = 1, F = 1, i ++;
				else ans[i] = 2, F = 0, i ++;
		}
		if(now == k) {now = 0, ans[i] = 2, b --;}
		else {a --, now ++ , ans[i] = 1;}
	}

    for(int i = 1; i <= n; i ++)
        if(ans[i] == 1) {if(flag == 1) printf("G"); else printf("B");}
        else {if(flag == 1) printf("B"); else printf("G");}

	return 0;
}