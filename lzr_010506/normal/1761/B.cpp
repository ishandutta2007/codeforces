#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N] , tp;
bool vis[N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		tp = 0;
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; ++ i)
			vis[i] = false;
		int cnt = 0;
		for(int i = 1 ; i <= n ; ++ i)
		{
			scanf("%d", a + i);
			if(!vis[a[i]]) ++ cnt , vis[a[i]] = true;
		}
		if(cnt >= 3) printf("%d\n" , n);
		else
			printf("%d\n" , n / 2 + 1);
	}
}