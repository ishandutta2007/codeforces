#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300004;
struct p{
	int x,y,z;
	bool operator<(const p &k)const{
		return k.z>z;
	}
}a[N];
int n,m,i,j,k,f[N],g[N],h[N],t[N],v[N],p[N],x,y,s;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);		
	for(i=m;i;i--){
		x=a[i].y;y=i;
		t[++k]=h[x];h[x]=k;v[k]=y;
	}
	for(i=1;i<=m;i++){
		j=a[i].x;
		f[i]=max(f[i],g[j]);
		for(k=h[j];k;k=t[k])
			if(a[v[k]].z<a[i].z)
				f[i]=max(f[i],f[v[k]]+1),
				g[j]=max(g[j],f[v[k]]+1);
			else
				break;
		h[j]=k;
		s=max(f[i]+1,s);
	}
	printf("%d",s);
}