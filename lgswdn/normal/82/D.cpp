#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],f[N][N],qwq[N][N];

void upd(int x,int y,int i,int j,int val) {
	if(val<f[x][y]) {
		f[x][y]=val;
		qwq[x][y]=j;
	}
}
void print(int i,int j) {
	if(i==0) return;
	print(i-1,qwq[i][j]);
	if(j==2*i) printf("%d %d\n",qwq[i][j],2*i+1);
	else if(j==2*i+1) printf("%d %d\n",qwq[i][j],2*i);
	else printf("%d %d\n",2*i,2*i+1);
}

int main() {
	n=read();
	rep(i,1,n) a[i]=read();
	if(n==1) {
		printf("%d\n%d\n",a[1],1);
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	f[1][1]=max(a[2],a[3]), f[1][2]=max(a[1],a[3]), f[1][3]=max(a[1],a[2]);
	qwq[1][1]=qwq[1][2]=qwq[1][3]=1;
	rep(i,1,n/2) rep(j,1,2*i+1) {
		upd(i+1,j,i,j,f[i][j]+max(a[2*i+2],a[2*i+3]));
		upd(i+1,2*i+2,i,j,f[i][j]+max(a[2*i+3],a[j]));
		upd(i+1,2*i+3,i,j,f[i][j]+max(a[2*i+2],a[j]));
	}
	int ans=0x3f3f3f3f,qwqj=0;
	rep(j,1,n/2*2+1) {
		if(f[n/2][j]+a[j]<=ans) {
			ans=f[n/2][j]+a[j];
			qwqj=j;
		}
	}
	printf("%d\n",ans);
	print(n/2,qwqj);
	if(qwqj<=n) printf("%d\n",qwqj);
	return 0;
}