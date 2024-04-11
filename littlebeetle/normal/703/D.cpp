#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,m,i,j,a[N],s[N],d[N],f[N],t[N],ans[N];
struct p{
	int l,r,id;
	bool operator<(const p &k)const{
		return k.r>r;
	}
}x[N];
bool cmp(int x,int y){
	if(a[x]==a[y])
		return x<y;
	return a[x]<a[y];
}
void add(int x,int y){
	while(x<=n)
		t[x]^=y,x+=x&-x;
}
int sum(int x){
	int s=0;
	for(;x;x-=x&-x)
		s^=t[x];
	return s;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),d[i]=i,s[i]=s[i-1]^a[i];
	sort(d+1,d+n+1,cmp);
	for(i=1;i<=n;i++)
		if(a[d[i]]==a[d[i-1]])
			f[d[i]]=d[i-1];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d%d",&x[i].l,&x[i].r),x[i].id=i,ans[i]=s[x[i].r]^s[x[i].l-1];
	sort(x+1,x+m+1);
	for(i=1,j=1;i<=n;i++){
		add(i,a[i]);
		if(f[i])
			add(f[i],a[i]);
		while(x[j].r==i)
			ans[x[j].id]^=sum(x[j].r)^sum(x[j].l-1),j++;
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}