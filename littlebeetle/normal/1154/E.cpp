#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
int n,k,i,a[N],l[N],r[N],d[N],sum,opt,x,y,z,t,id[N];
bool u[N];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),d[i]=i;
	sort(d+1,d+n+1,cmp);
	for(i=0;i<=n;i++)
		r[i]=i+1;
	for(i=1;i<=n+1;i++)
		l[i]=i-1;
	i=1;
	while(sum<n){
		opt++;
		while(u[d[i]])
			i++;
		x=d[i];
		u[x]=1;
		sum++;
		id[x]=opt%2;
		t=k;
		y=x;
		while(t--&&l[y]>0){
			y=l[y];
			u[y]=1;
			sum++;
			id[y]=opt%2;
		}
		y=l[y];
		t=k;
		z=x;
		while(t--&&r[z]<=n){
			z=r[z];
			u[z]=1;
			sum++;
			id[z]=opt%2;
		}
		z=r[z];
		r[y]=z;l[z]=y;
	}
	for(i=1;i<=n;i++)
		printf("%d",2-id[i]);
}