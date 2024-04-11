#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3009;
typedef pair<int,int> pii;
typedef vector<int> vi;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,a[N],f[N][N];
vi p[N];

int main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) rep(j,i,n) f[i][j]=j-i+1;
		rep(i,1,n) p[i].clear();
		rep(i,1,n) a[i]=read(), p[a[i]].push_back(i);
		per(l,n,1) rep(r,l,n) {
			if(l==r) f[l][r]=0;
			else {
				f[l][r]=f[l+1][r]+1;
				for(int k:p[a[l]]) if(l<=k&&k<=r)  f[l][r]=min(f[l][r],f[l][k-1]+f[k][r]);
			}
		}
		printf("%d\n",f[1][n]);
	}
	return 0;
}