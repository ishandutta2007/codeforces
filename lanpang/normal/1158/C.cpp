#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , tp , a[maxn] , nn;
struct mmp{
	int x , y;
	bool operator < (const mmp &op) const{
		if (y == op.y) return x < op.x;
		else return y > op.y;
	}
}b[maxn];
priority_queue<int> pq;

void put(int x)
{
	if (!a[x]) a[x] = nn--;
}

void work()
{
	int i , j;
	scanf("%d",&n);
	tp = 0;
	for (i = 1 ; i <= n ; i++)
	{
		a[i] = 0;
		scanf("%d",&j);
		if (j != -1) b[++tp] = {i,j};
	}
	sort(b+1,b+tp+1);
	nn = n;
	if (tp >= 1 && b[1].y == n+1) 
	{
		nn++;
		a[n+1] = 0;
	}		
	while (!pq.empty()) pq.pop();
	for (i = 1 ; i <= tp ; i++)
	{
		while (!pq.empty() && pq.top() >= b[i].y) pq.pop();
		if (!pq.empty() && pq.top() > b[i].x)
		{
			printf("-1\n");
			return;
		}
		put(b[i].y);
		put(b[i].x);
		pq.push(b[i].x);
	}
	for (i = 1 ; i <= n ; i++)
	{
		put(i);
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int i , j;
	cin >> T;
	while (T--)
		work();
	return 0;
}