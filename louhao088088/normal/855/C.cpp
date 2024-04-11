#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=2e5+5,mod=1e9+7;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,a[maxn],b[maxn],f[maxn][15][3],c,d,g[15][3],res=0;vector<int>e[maxn];
void dfs(int x,int fa){
	f[x][0][0]=c-1;
	f[x][1][1]=1;
	f[x][0][2]=m-c;
	for(auto i:e[x])if(i^fa){
		dfs(i,x);
		for(int j=0;j<=d;j++)g[j][2]=g[j][1]=g[j][0]=0;
		for(int j=0;j<=d;j++){
			for(int k=0;k<=d-j;k++){
				(g[j+k][0]+=f[x][j][0]*((f[i][k][0]+f[i][k][1]+f[i][k][2])%mod))%=mod;
				(g[j+k][1]+=f[x][j][1]*f[i][k][0])%=mod;
				(g[j+k][2]+=f[x][j][2]*((f[i][k][0]+f[i][k][2])%mod))%=mod;
			}
		}
		for(int j=0;j<=d;j++)f[x][j][1]=g[j][1],f[x][j][0]=g[j][0],f[x][j][2]=g[j][2];
	}
}
    
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].pb(y),e[y].pb(x);
	c=read(),d=read();
	dfs(1,0);
	for(int i=0;i<=d;i++)res=(res+f[1][i][1]+f[1][i][0]+f[1][i][2])%mod;
	cout<<res<<endl;
 	return 0;
}