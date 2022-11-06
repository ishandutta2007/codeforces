#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
string s;
inline void solve()
{
	int n,m,cnt=0;
	register int i;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(char c:s)
			if(c=='#')
				cnt++;
	}
	if(cnt==n*m)
		cout<<sub(qpow(2,n*m),1)<<endl;
	else
		cout<<qpow(2,cnt)<<endl;
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}