#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 200005
using namespace std;

int n,fa[N],bin[N],sz[N],a[N]; bool vis[N],mrk[N];
int getfa(int x){ return (x==fa[x])?x:fa[x]=getfa(fa[x]); }
int main(){
	scanf("%d",&n);
	int i,j,ans=1;
	for (i=1; i<=n; i++) fa[i]=i;
		for (bin[0]=1,i=1; i<=n; i++) bin[i]=bin[i-1]*2%mod;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]);
		fa[i]=getfa(a[i]);
	}
	for (i=1; i<=n; i++) sz[getfa(i)]++;
	for (i=1; i<=n; i++) if (getfa(i)==i){
		for (j=i; !vis[j]; j=a[j]) vis[j]=1;
		int tmp=0;
		for (; !mrk[j]; j=a[j]){tmp++;mrk[j]=1;}
		ans=(ll)ans*bin[sz[i]-tmp]%mod*(bin[tmp]-2+mod)%mod;
	}
	printf("%d\n",(ans)%mod);
	return 0;
}