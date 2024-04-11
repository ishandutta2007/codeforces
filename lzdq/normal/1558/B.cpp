#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=4e6+5;
int n,m;
int f[MAXN],s[MAXN],g[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	f[1]=s[1]=1;
	for(int i=2; i<=n; i++){
		g[i]=(g[i-1]+g[i])%m;
		f[i]=(1ll*s[i-1]+g[i]+(i+1>>1))%m;
		for(int d=2; i*d<=n; d++){
			g[i*d]=(g[i*d]+f[i])%m;
			if(d*i+d<=n) g[d*i+d]=(g[d*i+d]-f[i]+m)%m;
		}
		s[i]=(s[i-1]+f[i])%m;
	}
	printf("%d\n",f[n]);
	return 0;
}