#include<cstdio>
#include<cstring>
using namespace std;
const int N=5002;
typedef long long ll;
int n,k,x,i,j,l,a[N],q[N],s,e;
ll f[N],g[N],ans=-1;
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&k,&x);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	memset(f,-10,sizeof(f));
	memset(g,-10,sizeof(g));	
	f[0]=0;
	while(x--){
		q[s=e=0]=0;
		for(i=1;i<=n;i++){
			while(s<=e&&q[s]<i-k)
				s++;
			g[i]=f[q[s]]+a[i];
			while(s<=e&&f[q[e]]<f[i])
				e--;
			q[++e]=i;
		}
		for(i=0;i<=n;i++)
			f[i]=g[i];
	}
	for(i=1;i<=n;i++)
		if(n-i<k)
			ans=max(ans,f[i]);
	printf("%I64d",ans);
}