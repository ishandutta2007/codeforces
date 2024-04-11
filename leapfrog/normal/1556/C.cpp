#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n;ll s[10005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(s[i]),s[i]=i&1?s[i]:-s[i],s[i]+=s[i-1];
	ll rs=0;for(int i=1;i<=n;i++) if(i&1)//i-1 -> i
	{
		if(i^n) rs+=s[i]-max(s[i-1],s[i+1]);
		ll mn=s[i+1];for(int j=i+3;j<=n;j++) if(!(j&1))
			rs+=max(mn-max(s[i-1],s[j])+1,0ll),mn=min(mn,s[j]);
	}
	return printf("%lld\n",rs),0;
}