#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 7009
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int n,m,cnt,p[N]; bool mu[N],vis[N]; bitset<N> a[100009],b[N],c[N];
int main(){
	n=read(); m=read();
	int i,j,x,y,z; mu[1]=1;
	for (i=2; i<N; i++){
		if (!vis[i]){ mu[i]=1; p[++cnt]=i; }
		for (j=1; j<=cnt && i*p[j]<N; j++){
			vis[i*p[j]]=1;
			if (i%p[j]) mu[i*p[j]]=mu[i];
			else{
				mu[i*p[j]]=0; break;
			}
		}
	//	cerr<<i<<' '<<mu[i]<<'\n';
	}
	for (i=1; i<N; i++)
		for (j=1; i*j<N; j++) if (mu[j]) b[i][i*j]=1;
	for (i=1; i<N; i++)
		for (j=1; j<=i; j++) c[i][j]=(i%j==0);
	while (m--){
		i=read();
		if (i==1){
			x=read(); y=read(); a[x]=c[y];
		} else if (i==2){
			x=read(); y=read(); z=read();
			a[x]=a[y]^a[z];
		} else if (i==3){
			x=read(); y=read(); z=read();
			a[x]=a[y]&a[z];	
		} else if (i==4){
			x=read(); y=read();
			putchar('0'+((a[x]&b[y]).count()&1));
		//	puts("");
		}
	//	for (x=1; x<=4; x++){
	//		for (j=1; j<10; j++) putchar('0'+a[x][j]);puts("");}
	}
	puts("");
	return 0;
}