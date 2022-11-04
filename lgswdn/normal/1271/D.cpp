#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,k,a[N],b[N],c[N],lst[N],p[N][N],cnt[N],f[N][N],ans=-0x3f3f3f3f;
bool cond[N];

bool cmp(const int &x,const int &y) {return c[x]>c[y];}

int main() {
	n=read(), m=read(), k=read();
	rep(i,1,n) a[i]=read(), b[i]=read(), c[i]=read();
	rep(i,1,m) {
		int u=read(), v=read();
		lst[v]=max(lst[v],u), cond[v]=1;
	}
	rep(i,1,n) {
		if(lst[i]) p[lst[i]][++cnt[lst[i]]]=i;
	}
	rep(i,1,n) {
		if(!cond[i]) p[i][++cnt[i]]=i;
	}
	rep(i,1,n) {
		if(cnt[i]) sort(p[i]+1,p[i]+cnt[i]+1,cmp);
	}
	/*
	rep(i,1,n) {
		printf("The Connection To %d: ",i);
		rep(j,1,cnt[i]) printf("%d ",p[i][j]);
		puts("");
	}
	*/
	memset(f,-0x3f,sizeof(f));
	f[0][k]=0;
	rep(i,1,n) {
		rep(j,0,5000) {
			if(f[i-1][j]<0) continue;
			if(j<a[i]) continue;
			f[i][j+b[i]]=max(f[i][j+b[i]],f[i-1][j]);
			int sum=0;
			rep(k,1,cnt[i]) if(j+b[i]-k>=0) {
				sum+=c[p[i][k]];
				f[i][j+b[i]-k]=max(f[i][j+b[i]-k],f[i-1][j]+sum);
			}
		}
	}
	/*
	rep(i,1,n) {
		rep(j,0,6) {
			printf("%d ",f[i][j]);
		}
		puts("");
	}
	*/
	rep(j,0,5000) ans=max(ans,f[n][j]);
	if(ans<0) puts("-1");
	else printf("%d\n",ans);
	return 0;
}