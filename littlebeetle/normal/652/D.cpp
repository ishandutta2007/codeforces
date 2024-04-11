#include<cstdio>
#include<algorithm>
using namespace std;
const int N=400002;
int n,m,i,a[N],d[N],b[N],c[N],ans[N];
struct q{
	int l,r,id;
	bool operator<(const q &k)const{
		return k.r>r;
	}
}x[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
void add(int x){
	while(x)
		c[x]++,x-=x&-x;
}
int sum(int x){
	int s=0;
	for(;x<=m;x+=x&-x)
		s+=c[x];
	return s;
}
int main(){
	scanf("%d",&n);
	m=n*2;
	for(i=1;i<=m;i++)
		scanf("%d",a+i),d[i]=i;
	sort(d+1,d+m+1,cmp);
	for(i=1;i<=m;i++)
		b[d[i]]=b[d[i-1]]+1;
	for(i=1;i<=n;i++)
		x[i].l=b[i*2-1],x[i].r=b[i*2],x[i].id=i;
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++){
		ans[x[i].id]=sum(x[i].l);
		add(x[i].l);
	}
	for(i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}