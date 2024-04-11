#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , k , f[110] , s[2] , cnt , a[110][110] , b[110][110] , c[110][110] , si; 

LL qp(LL x , LL y)
{
	if (!y) return 1ll;
	LL z = qp(x,y/2);
	if (y%2) return z*z%mod*x%mod;
	else return z*z%mod;
}

void jzcf1()
{
	for (int i = 0 ; i <= si ; i++)
		for (int j = 0 ; j <= si ; j++)
		{ 
			c[i][j] = a[i][j];
			a[i][j] = 0;
		} 
	for (int i = 0 ; i <= si ; i++)
		for (int j = 0 ; j <= si ; j++)
			for (int k = 0 ; k <= si ; k++)
				a[i][j] = (a[i][j]+c[i][k]*c[k][j])%mod;
}

void jzcf2()
{
	for (int i = 0 ; i <= si ; i++)
		for (int j = 0 ; j <= si ; j++)
		{ 
			c[i][j] = a[i][j];
			a[i][j] = 0;
		} 
	for (int i = 0 ; i <= si ; i++)
		for (int j = 0 ; j <= si ; j++)
			for (int k = 0 ; k <= si ; k++)
				a[i][j] = (a[i][j]+b[i][k]*c[k][j])%mod;
}

void qp_mx(LL t)
{
	if (t == 1) return;
	qp_mx(t/2);
	jzcf1();
	if (t%2) jzcf2();
}

int main()
{
	LL i , j , t1 , t2;
	cin >> n >> k;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&f[i]);
		s[f[i]]++;
	}
	for (i = 1 ; i <= s[0] ; i++)
		if (f[i]) cnt++;
	si = min(s[0],s[1]);
	for (i = 0 ; i <= si ; i++)
	{
		t1 = t2 = 0;
		if (i) 
		{
			t1 = i*i;
			a[i][i-1] = (a[i][i-1]+t1*2*qp(n*(n-1),mod-2))%mod;
		}
		if (i < si) 
		{
			t2 = (s[0]-i)*(s[1]-i);
			a[i][i+1] = (a[i][i+1]+t2*2*qp(n*(n-1),mod-2))%mod;
		}
		a[i][i] = (a[i][i]+(n*(n-1)/2-t1-t2)*2*qp(n*(n-1),mod-2))%mod;
	}
	for (i = 0 ; i <= si ; i++)
		for (j = 0 ; j <= si ; j++)
			b[i][j] = a[i][j];
	qp_mx(k);
	cout << a[cnt][0] << "\n";
	return 0;
}