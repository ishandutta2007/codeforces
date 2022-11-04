#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;
typedef pair<int,int> pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,p,a[N];
bool vst[N];

signed main() {
	T=read();
	while(T--) {
		n=read(), p=read();
		rep(i,1,n) a[i]=read(), vst[i]=0;
		priority_queue<pii>q;
		rep(i,1,n) q.push(pii(-a[i],i));
		vst[0]=vst[n]=vst[n+1]=1;
		int cnt=0,ans=0;
		while(!q.empty()) {
			int x=-q.top().first, pos=q.top().second; q.pop();
			if(vst[pos]&&vst[pos-1]) continue;
			if(x>=p) continue;
			int l=pos, r=pos;
			while(l-1>=1&&a[l-1]%x==0&&!vst[l-1]) l--, vst[l]=1, cnt++, ans+=x;
			while(r<=n&&a[r+1]%x==0&&!vst[r]) vst[r]=1, r++, cnt++, ans+=x;
		}
		ans+=(n-1-cnt)*p;
		printf("%lld\n",ans);
	}
	return 0;
}