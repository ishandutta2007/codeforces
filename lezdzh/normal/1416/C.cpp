#include<cstdio>

using namespace std;

int n;
int a[300001],p[300001],b[300001],c[300001];
long long da[101][2];
void xg(int p,int cc){
	for(;p<=n;p+=p&-p)
		c[p]+=cc;
}
int cx(int p){
	int ans=0;
	for(;p;p-=p&-p)
		ans+=c[p];
	return ans;
}
void cz(int l,int r,int w){
	if(l>r||w<0)return;
	long long ans1=0,ans0=0;
	for(int i=l;i<=r;i++)
		if(!(a[p[i]]>>w&1))xg(p[i],1);
		else ans1+=cx(p[i]);
	for(int i=l;i<=r;i++)
		if(!(a[p[i]]>>w&1))xg(p[i],-1);
	for(int i=l;i<=r;i++)
		if(a[p[i]]>>w&1)xg(p[i],1);
		else ans0+=cx(p[i]-1);
	for(int i=l;i<=r;i++)
		if(a[p[i]]>>w&1)xg(p[i],-1);
	//printf("%d %d %d %lld %lld\n",l,r,w,ans0,ans1);
	da[w][0]+=ans0;
	da[w][1]+=ans1;
	b[0]=0;
	for(int i=l;i<=r;i++)
		if(!(a[p[i]]>>w&1))
			b[++b[0]]=p[i];
	int mid=b[0];
	for(int i=l;i<=r;i++)
		if(a[p[i]]>>w&1)
			b[++b[0]]=p[i];
	for(int i=1;i<=b[0];i++)
		p[i+l-1]=b[i];
	cz(l,l+mid-1,w-1);
	cz(l+mid,r,w-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	cz(1,n,30);
	int ans=0;
	long long sum=0;
	for(int i=30;i>=0;i--)
		if(da[i][0]>da[i][1])ans+=1<<i,sum+=da[i][1];
		else sum+=da[i][0];
	printf("%lld %d\n",sum,ans);
}