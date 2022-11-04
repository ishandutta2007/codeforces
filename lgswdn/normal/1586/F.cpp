#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1009;
int n,bs[N],col[N][N],tc[N],k,ans,bc[N][N];

bool check(int p) {
	int sz=1;
	rep(i,1,p) {
		rep(j,1,n) bc[j][i]=(j-1)/sz%k;
		sz*=k;
		if(sz>1000000000) return 1;
	}
	if(sz>=n) return 1;
	else return 0;
}

signed main() {
	n=read(), k=read();
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			rep(i,1,n) rep(j,1,mid) col[i][j]=bc[i][j];
			r=mid-1;
		} else l=mid+1;
	}
	/*
	rep(i,1,n) {
		rep(j,1,ans) cout<<col[i][j]<<" ";
		puts("");
	}
	//*/
	printf("%d\n",ans);
	rep(i,1,n) {
		rep(j,i+1,n) {
			per(p,ans,1) {
				if(col[i][p]!=col[j][p]) {printf("%d ",p); break;}
			}
		}
	}
	return 0;
}