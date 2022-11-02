//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n;pair<int,int>p[300005];map<int,int>A,B;
const int P=998244353;int fc[300005];map<pair<int,int>,int>mp;
int main()
{
	read(n),fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	for(int i=1,a,b;i<=n;i++) read(a),read(b),mp[p[i]=make_pair(a,b)]++,A[a]++,B[b]++;
	int c1=1;for(auto x:A) c1=1ll*c1*fc[x.second]%P;
	int c2=1;for(auto x:B) c2=1ll*c2*fc[x.second]%P;
	int c3=1;sort(p+1,p+n+1);for(auto x:mp) c3=1ll*c3*fc[x.second]%P;
	for(int i=2;i<=n;i++) if(p[i].second<p[i-1].second) c3=0;
	return printf("%lld\n",(1ll*fc[n]-c1+P-c2+P+c3)%P),0;
}