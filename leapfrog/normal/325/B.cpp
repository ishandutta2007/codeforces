//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
ll n;vector<ll>r;
inline void flush() {sort(r.begin(),r.end()),r.empty()?puts("-1"):0;for(auto i:r) printf("%lld\n",(long long)i);}
inline ll calc(ll a,ll b) {return (2*a+1)*(a+b);}
inline void solve(ll d)
{
	ll c=1ll<<d,le=0,ri=1,rs=-1;c--;while(calc(ri,c)<=n) ri<<=1;
	while(le<=ri) {ll md=(le+ri)>>1;if(calc(md,c)<=n) rs=md,le=md+1;else ri=md-1;}
	if(~rs&&calc(rs,c)==n) r.push_back((2*rs+1)<<d);
}
int main() {read(n);for(int i=0;i<63;i++) solve(i);return flush(),0;}