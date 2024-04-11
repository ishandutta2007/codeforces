//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
mt19937 rnd(time(0));ll n;int K,cnt=0;char ch[15];
inline ll qry(ll l,ll r) {return printf("%lld %lld\n",l,r),fflush(stdout),scanf("%s",ch),*ch=='Y';if(++cnt>4500) exit(0);}
int main()
{
	read(n),read(K);ll le=1,ri=n;
	while(1)
	{
		for(;ri-le>50;le=max(1ll,le-K),ri=min(n,ri+K)) {ll md=(le+ri)>>1;if(qry(le,md)) ri=md;else le=md+1;}
		ll qwq=rnd()%(ri-le+1)+le;if(qry(qwq,qwq)) return 0;else le=max(le-K,1ll),ri=min(ri+K,n);
	}
	return 0;
}