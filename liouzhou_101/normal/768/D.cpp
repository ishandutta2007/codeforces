#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 1010;

ld lg[MAXN], pp[MAXN];
ld C[MAXN][MAXN];

ld f[MAXN];

int main()
{
	
	for (int i=1; i<=1000; ++i)
	{
		lg[i] = log(i);
		pp[i] = pp[i-1]+lg[i];
	}
	for (int i=1; i<=1000; ++i)
		for (int j=1; j<=1000; ++j)
			C[i][j] = pp[i]-pp[j]-pp[i-j];
	int kk, q;
	cin >> kk >> q;
	while (q--)
	{
		int p;
		scanf("%d", &p);
		ll L = kk, R = 100000;
		ll ans = R;
		while (L<=R)
		{
			ll n = (L+R)/2;
			/*
			f[1] = 1;
			for (int k=2; k<=kk; ++k)
			{
				f[k] = 1;
				for (int j=1; j<k; ++j)
				{
					f[k] -= f[j]*exp(C[k][j]+n*(lg[j]-lg[k]));
				}
			}
			*/
			
			ld f = 1;
			for (int k=1; k<kk; ++k)
			{
				if (k&1)
					f -= exp(C[kk][k]+n*(lg[k]-lg[kk]));
				else
					f += exp(C[kk][k]+n*(lg[k]-lg[kk]));
			}
			
			if (p<=f*2000)
			{
				ans = n;
				R = n-1;
			}
			else
				L = n+1;
		}
		cout << ans << endl;
	}
	/*
	for (int n=1; n<=10; ++n)
	{
		f[1] = 1;
		for (int k=2; k<=n; ++k)
		{
			f[k] = 1;
			for (int j=1; j<k; ++j)
			{
				f[k] -= f[j]*exp(C[k][j]+n*(lg[j]-lg[k]));
			}
			printf("%.2f ", f[k]*2000);
		}
		puts("");
	}
	*/
	return 0;
}