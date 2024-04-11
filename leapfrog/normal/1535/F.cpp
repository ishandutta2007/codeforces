//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
int n;map<string,vector<string> >mp;
int main()
{
	read(n);string s,t;ll r1=0,r2=0,rt=1ll*n*(n-1)/2;
	for(int i=1;i<=n;i++) cin>>s,t=s,sort(t.begin(),t.end()),mp[t].push_back(s);
	int m=s.size();for(auto &x:mp)
	{
		vector<string>v=x.second;sort(v.begin(),v.end());
		int ln=v.size();for(int i=0,j,l,r,f1,f2;i<ln;i++) for(j=i+1;j<ln;j++)
		{
			f1=f2=1,l=0,r=m-1;
			while(v[i][l]==v[j][l]) l++;
			while(v[i][r]==v[j][r]) r--;
			for(;l<r&&(f1||f2);l++) f1&=v[i][l]<=v[i][l+1],f2&=v[j][l]<=v[j][l+1];
			(f1||f2?r1:r2)++;
		}
	}
	ll r3=rt-r1-r2;return printf("%lld\n",1337*r3+r1+2*r2),0;
}