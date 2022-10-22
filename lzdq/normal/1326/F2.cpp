#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1<<18|5;
int n;
char a[20][20];
int p[20],ppc[MAXN];
ll f[MAXN][20],sum[20][MAXN],ans[MAXN];
inline void FWTor(ll *a,int ty){
	for(int mid=1; mid<1<<n; mid<<=1)
		for(int i=0; i<1<<n; i+=mid*2)
			for(int j=0; j<mid; j++)
				a[i+j+mid]+=a[i+j]*ty;
}
inline void FWTand(ll *a,int ty){
	for(int mid=1; mid<1<<n; mid<<=1)
		for(int i=0; i<1<<n; i+=mid*2)
			for(int j=0; j<mid; j++)
				a[i+j]+=a[i+j+mid]*ty;
}
bool vis[MAXN];
ll Calc(int t){
	if(vis[t]) return ans[t];
	for(int j=0; j<1<<n; j++){
		ll m=1;
		int s=n;
		for(int k=1; k<=*p; k++)
			m*=sum[p[k]][j],s-=p[k];
		while(s--) m*=sum[1][j];
		if(ppc[j]%2==n%2) ans[t]+=m;
		else ans[t]-=m;
	}
	vis[t]=1;
	return ans[t];
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%s",a[i]+1);
	for(int i=1; i<1<<n; i++){
		ppc[i]=ppc[i>>1]+(i&1);
		*p=0;
		for(int j=1; j<=n; j++)
			if(i&1<<j-1) p[++*p]=j;
		if(*p==1) f[i][p[1]]=1;
		else for(int j=1; j<=*p; j++)
			for(int k=1; k<=*p; k++)
				if(j!=k&&a[p[j]][p[k]]=='1') f[i][p[j]]+=f[i^1<<p[j]-1][p[k]];
		for(int j=1; j<=*p; j++)
			f[i][0]+=f[i][p[j]];
		sum[*p][i]=f[i][0];
	}
	for(int i=1; i<=n; i++)
		FWTor(sum[i],1);
	for(int i=0; i<1<<n-1; i++){
		*p=0;
		for(int j=0; j<n-1; j++)
			if(i&1<<j){
				if(j&&i&1<<j-1) p[*p]++;
				else p[++*p]=2;
			}
		sort(p+1,p+*p+1);
		int t=0;
		for(int j=0,k=1; k<=*p; j++,k++){
			int s=p[k]-1;
			while(s--) t|=1<<j++;
		}
		ans[i]=Calc(t);
	}
	n--;
	FWTand(ans,-1);
	for(int i=0; i<1<<n; i++)
		printf("%lld ",ans[i]);
	puts("");
	return 0;
}