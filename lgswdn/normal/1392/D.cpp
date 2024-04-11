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

const int N=1e6+9;
int T,n,a[N],f[N][2][2];
char s[N];

int dp() {
	//cout<<"DP of "<<a[1]<<" "<<a[2]<<endl;
	rep(i,1,n) rep(j,0,1) rep(k,0,1) f[i][j][k]=n;
	f[2][a[1]][a[2]]=0;
	rep(i,3,n) rep(j,0,1) rep(k,0,1) rep(l,0,1) if(j!=k||l!=k) { //j k l f[i-1][j][k] f[i][k][l]
		f[i][k][l]=min(f[i][k][l],f[i-1][j][k]+(a[i]!=l));
		//cout<<"F "<<i<<" "<<k<<" "<<l<<" "<<f[i][k][l]<<endl;
	}
	int ans=n;
	rep(i,0,1) rep(j,0,1) if((i!=j||i!=a[1])&&(j!=a[1]||j!=a[2])) ans=min(ans,f[n][i][j]);
	return ans;
}

signed main() {
	T=read();
	while(T--) {
		n=read();
		scanf("%s",s+1);
		rep(i,1,n) a[i]=(s[i]=='L');
		int a1=a[1], a2=a[2];
		int ans=n;
		rep(i,0,1) rep(j,0,1) {
			int res=(a[1]!=i)+(a[2]!=j);
			a[1]=i, a[2]=j;
			ans=min(ans,res+dp());
			a[1]=a1, a[2]=a2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}