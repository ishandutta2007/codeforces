#include <bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		char ch[110][110];
		set<int> st[110];
		for(int i = 1; i <= n; i ++)
			scanf("%s", ch[i] + 1);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if(i == j || ch[i][j] == '1') st[j].insert(i);
		for(int i = 1; i <= n; i ++)
		{
			printf("%d ", (int)st[i].size());
			for(auto &x : st[i]) printf("%d ", x);
			puts("");
		}
	}
	return 0;
}