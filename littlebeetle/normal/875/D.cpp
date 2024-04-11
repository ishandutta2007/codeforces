#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003,K=31;
int n,i,j,k,a[N],d[N],l[N],r[N],L[N][K],R[N][K],vis[N],p,q;
long long ans;
bool cmp(int x,int y){
	return a[x]<a[y];
}
void Delete(int x){
	l[r[x]]=l[x];
	r[l[x]]=r[x];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		l[i]=i-1;r[i]=i+1;
		d[i]=i;
	}
	for(i=1;i<=n;i++)
		for(j=0;j<K;j++){
			L[i][j]=L[i-1][j];
			if(a[i]>>j&1)
				L[i][j]=i;
		}
	for(j=0;j<K;j++)
		R[n+1][j]=n+1;
	for(i=n;i;i--)
		for(j=0;j<K;j++){
			R[i][j]=R[i+1][j];
			if(a[i]>>j&1)
				R[i][j]=i;
		}
	sort(d+1,d+n+1,cmp);
	for(k=1;k<=n;k++){
		i=d[k];
		vis[i]=1;
		if(vis[l[i]])
			Delete(l[i]);
		if(vis[r[i]])
			Delete(r[i]);
		p=l[i];
		q=r[i];
		for(j=0;j<K;j++)
			if(!(a[i]>>j&1))
				p=max(p,L[i][j]),
				q=min(q,R[i][j]);
		ans+=1ll*(r[i]-i)*(i-l[i])-1ll*(q-i)*(i-p);
	}
	printf("%I64d",ans);
}