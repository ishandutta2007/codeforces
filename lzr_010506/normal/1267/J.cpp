#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int n, m, ans;
int a[N], b[N];

inline int calc(int n, int s)
{
	if(n % s == 0) return n / s;
	int num = n / s;
	int rem = n % s;
	if(s - 1 - rem <= num) return num + 1;
	else return 0;
} 

inline void check(int s)
{
	int sum = 0;
	for(int i=1; i<=m; ++i)
	{
		int t = calc(b[i], s);
		if(!t) return;
		sum += t;
		if(sum > ans) return;
	}
	ans = min(ans, sum);
}

int main()
{
	/*
	for(;;)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cout << calc(x, y) << "\n";
	}
	*/
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int cnt = 0, Min = n;
		m = 0;
		for(int i=1; i<=n; ++i)
		{
			++cnt;
			if(i == n || a[i] != a[i+1])
			{
				b[++m] = cnt;
				Min = min(Min, cnt);
				cnt = 0;
			} 
		}
		
		if(m == 1)
		{
			printf("1\n");
			continue;
		}
		
		ans = n;
//		check(Min);
//		check(Min + 1);
		for(int i=2; i<=Min+1; ++i)
		{
			if(calc(Min, i)) check(i);
		} 
				
		printf("%d\n", ans);
	}
}