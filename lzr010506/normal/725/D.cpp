#include <bits/stdc++.h>
#define pq priority_queue
#define ll long long
#define N 300010
#define vl vector<ll>
using namespace std;
int n;
ll A[N], B[N];
int id[N];
pq<ll, vl, greater<ll> > hp; 
bool cmp(int x, int y) 
{
	return A[x] < A[y];
}

void Init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%I64d%I64d", &A[i], &B[i]), id[i] = i;
}

void Work()
{
	sort(id + 1, id + n + 1, cmp);
	int l = n + 1, d = 0, now = 0; 
	ll tmp = A[1]; 
	int ans = n;
	while(l >= 1) 
	{
		while (l > 1 && A[id[l - 1]] > tmp)
		{
			l --; 
			if (id[l] != 1)	hp.push(B[id[l]] - A[id[l]] + 1), now ++;
		}
		ans = min(ans, now - d + 1); 
		if (hp.size() && tmp >= hp.top()) tmp -= hp.top(), hp.pop(), d ++; 
		else break;
	}
	printf("%d\n", ans); 
}

int main() 
{
	Init();
	Work();
	return 0;
}