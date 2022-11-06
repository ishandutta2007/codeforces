#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,p[N],a[N][N],ux[N],uy[N],c[N];

bool check(int x,int y) {
	if(x>n||y>x||x<=0||y<=0||a[x][y]) return 0;
	else return 1;
}

int main() {
	n=read();
	rep(i,1,n) a[i][i]=p[i]=read();
	rep(i,1,n) ux[p[i]]=uy[p[i]]=i, c[i]=1;
	rep(t,1,n*(n-1)/2) {
		rep(i,1,n) if(c[i]<i) {
			if(check(ux[i]+1,uy[i])&&check(ux[i],uy[i]-1)) continue;
			else if(check(ux[i]+1,uy[i])) a[ux[i]+1][uy[i]]=i, ux[i]++, c[i]++;
			else if(check(ux[i],uy[i]-1)) a[ux[i]][uy[i]-1]=i, uy[i]--, c[i]++;
			else return puts("-1"), 0;
		}
	}
	rep(i,1,n) {
		rep(j,1,i) printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}