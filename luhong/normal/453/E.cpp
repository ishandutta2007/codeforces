#include <cstdio>
#include <cstring>
#include <iostream>
#define T 350
#define MN 101000

typedef long long ll;
int s[MN], m[MN], r[MN];
ll w[MN / T + 5][MN];
ll sum[MN / T + 5];
int t[MN / T + 5];
bool ok[MN / T + 5];
int b[MN];
ll M[MN], R[MN];
int n; 

void init(int x)
{
	int l = x * T, r = std::min(n - 1, (x + 1) * T - 1);
	memset(b, 0, sizeof(b));
	memset(M, 0, sizeof(M));
	memset(R, 0, sizeof(R));
	for(int i = l; i <= r; i++)
	{
		if(s[i] != 0) ok[x] = 1;
		if(::r[i] != 0)
		{
			sum[x] += m[i]; 
			int t = m[i] / ::r[i];
			b[t]++; M[t] += m[i]; R[t] += ::r[i];
		}
	}
	ll sumM = 0;
	for(int i = 0; i <= 100000; i++)
	{
		w[x][i] += sumM;
		sumM += M[i];
	}
	ll sumR = 0;
	for(int i = 100000; i >= 0; i--)
	{
		sumR += R[i];
		w[x][i] += i * sumR;
	}
	
}

ll modify(int x, int L, int R, int tt)
{
	int l = x * T, r = std::min(n - 1, (x + 1) * T - 1);
	ll ans = 0;
	for(int i = l; i < L; i++) s[i] = std::min((ll)m[i], s[i] + 1ll * (tt - t[x]) * ::r[i]);
	for(int i = R + 1; i <= r; i++) s[i] = std::min((ll)m[i], s[i] + 1ll * (tt - t[x]) * ::r[i]);
	for(int i = L; i <= R; i++) 
	{
		ans = ans + std::min((ll)m[i], s[i] + 1ll * ::r[i] * (tt - t[x]));
		s[i] = 0;
	}
	if(L == l && R == r) ok[x] = 0;
	else ok[x] = 1;
	t[x] = tt;
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d%d", &s[i], &m[i], &r[i]);
	for(int i = 0; i <= (n - 1) / T; i++) init(i);
	int q; scanf("%d", &q);
	while(q--)
	{
		int t, L, R; scanf("%d%d%d", &t, &L, &R);
		L--; R--;
		int lb = L / T, rb = R / T;
		if(lb == rb) printf("%lld\n", modify(lb, L, R, t));
		else
		{
			ll ans = 0;
			ans += modify(lb, L, (lb + 1) * T - 1, t); 
			ans += modify(rb, rb * T, R, t);
			for(int i = lb + 1; i < rb; i++)
			{
				if(ok[i]) ans = ans + modify(i, i * T, (i + 1) * T - 1, t);
				else
				{
					if(t - ::t[i] > 100000) ans = ans + sum[i];
					else ans = ans + w[i][t - ::t[i]];
					::t[i] = t;
				}
			}
			printf("%lld\n", ans);
		}
	}
}