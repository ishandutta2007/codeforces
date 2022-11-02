#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int x,y,z;
	bool operator<(const p &k)const{
		return k.z>z;
	}
}a[N];
int n,m,f[N],i,j,k,u,v,U[N],V[N],ans;
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
int P(int x){
	return x==f[x]?x:f[x]=P(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);
	for(i=1;i<=m;){
		k=0;
		for(j=i;a[i].z==a[j].z;j++)
			U[j]=P(a[j].x),
			V[j]=P(a[j].y);
		for(j=i;a[i].z==a[j].z;j++){
			u=a[j].x;v=a[j].y;
			if(P(u)!=P(v))
				f[f[u]]=v;
			else
				if(U[j]!=V[j])
					ans++;
		}
		i=j;
	}
	printf("%d",ans);
}