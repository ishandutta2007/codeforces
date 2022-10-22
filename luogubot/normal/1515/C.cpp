#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,m,x,id[N];
#define pi pair<int,int>
#define fi first
#define se second
priority_queue<pi> q;
struct node{
	int id,v;
	bool operator < (const node &x) const {
		return v<x.v;
	}
}a[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read(),m=read(),x=read();
		For(i,1,n)a[i]=(node){i,read()};
		For(i,1,m)q.push(pi(0,i));
		sort(a+1,a+1+n);For(i,1,n){
			pi x=q.top();q.pop();
			id[a[i].id]=x.se,x.fi-=a[i].v;
			q.push(x);
		}int mn=1e9,mx=-1e9;while(!q.empty())mn=min(mn,-q.top().fi),mx=max(mx,-q.top().fi),q.pop();
		if(mx-mn>x)puts("NO");else{
			puts("YES");For(i,1,n)printf("%lld ",id[i]);puts("");
		}
	}
	return 0;
}