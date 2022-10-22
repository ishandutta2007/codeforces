#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2005,mod=1e9+7;
int n;
char s[MAXN],t[MAXN];
int ns[MAXN],nt[MAXN];
int f1[MAXN][MAXN],g[MAXN][MAXN],f2[MAXN][MAXN],ans;
inline void Add(int x1,int y1,int x2,int y2,int v){
	g[x1][y1]=(g[x1][y1]+v)%mod;
	g[x1][y2+1]=(g[x1][y2+1]-v+mod)%mod;
	g[x2+1][y1]=(g[x2+1][y1]-v+mod)%mod;
	g[x2+1][y2+1]=(g[x2+1][y2+1]+v)%mod;
}
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s%s",s+1,t+1);
		ans=0;
		for(int i=1; i<=n; i++){
			if(s[i]=='?') s[i]=2;
			else s[i]=s[i]-'0'+i&1;
			if(t[i]=='?') t[i]=2;
			else t[i]=t[i]-'0'+i&1;
		}
		ns[n+1]=nt[n+1]=n+1;
		for(int i=n; i; i--){
			if(s[i]==1) ns[i]=i;
			else ns[i]=ns[i+1];
			if(t[i]==1) nt[i]=i;
			else nt[i]=nt[i+1];
		}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				g[i][j]=0;
		Add(1,1,ns[1],nt[1],1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				if(s[i]&&t[j]) f1[i][j]=g[i][j],Add(i+1,j+1,ns[i+1],nt[j+1],f1[i][j]);
				g[i+1][j]=(g[i+1][j]+g[i][j])%mod;
				g[i][j+1]=(g[i][j+1]+g[i][j])%mod;
				g[i+1][j+1]=(g[i+1][j+1]-g[i][j]+mod)%mod;
			}
		reverse(s+1,s+n+1);
		reverse(t+1,t+n+1);
		ns[n+1]=nt[n+1]=n+1;
		for(int i=n; i; i--){
			if(s[i]==1) ns[i]=i;
			else ns[i]=ns[i+1];
			if(t[i]==1) nt[i]=i;
			else nt[i]=nt[i+1];
		}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				g[i][j]=0;
		Add(1,1,ns[1],nt[1],1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				if(s[i]&&t[j]) f2[i][j]=g[i][j],Add(i+1,j+1,ns[i+1],nt[j+1],f2[i][j]);
				g[i+1][j]=(g[i+1][j]+g[i][j])%mod;
				g[i][j+1]=(g[i][j+1]+g[i][j])%mod;
				g[i+1][j+1]=(g[i+1][j+1]-g[i][j]+mod)%mod;
			}
		reverse(s+1,s+n+1);
		reverse(t+1,t+n+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(s[i]&&t[j]) ans=(ans+1ll*abs(i-j)*f1[i][j]%mod*f2[n-i+1][n-j+1])%mod;
		printf("%d\n",ans);
	}
	return 0;
}