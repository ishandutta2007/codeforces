// By: Little09
// Problem: D. Dominoes
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=100000;
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int a,b,c,d;
ll bw,wb;
int main()
{
	init();
	int n;
	cin >> n;
	if (n==1)
	{
		char x=readchar(),y=readchar();
		if (x=='?'&&y=='?') a=2;
		else if (x==y) a=0;
		else a=1;
		cout << a << endl;
		return 0;
	}
	ll tmp=0,flag=0;
	wb=1,bw=1;
	for (int i=1;i<=n;i++)
	{
		char x=readchar();
		if (x=='W') a++;
		else if (x=='B') b++;
		char y=readchar();
		if (y=='W') c++;
		else if (y=='B') d++;
		if (x=='?'&&y=='?') tmp++;
		else if (x==y) flag=1;
		if (x=='B'||y=='W') wb=0;
		if (x=='W'||y=='B') bw=0;
	}
	ll res=0;
	if (flag==1) res=0;
	else 
	{
		res=ksm(2,tmp);
	}
	int w1=n-a-b,w2=n-c-d;
	ll ans=0;
	for (int i=0;i<=n;i++)
	{
		if (a>i||b>n-i||c>n-i||d>i) continue;
		ans=(ans+C(w1,i-a)*C(w2,i-d)%mod)%mod;
	}
	cout << (ans-res+bw+wb+mod)%mod;
	return 0;
}