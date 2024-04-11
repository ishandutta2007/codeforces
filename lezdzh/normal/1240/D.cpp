#include<cstdio>
#include<algorithm>

using namespace std;

long long pw(long long x,long long y,long long md){
	long long ans=1;
	for(;y;y>>=1,x=x*x%md)
		if(y&1)ans=ans*x%md;
	return ans;
}
const int md1=1000000009,sd1=32650157,ny1=pw(sd1,md1-2,md1),
	  md2=490086211,sd2=8770007,ny2=pw(sd2,md2-2,md2);
int a[300001],st[300001];
long long w[300001];
long long cc(int l,int r){
	if(l==r)return 0;
	int mid=l+r>>1;
	long long ans=cc(l,mid)+cc(mid+1,r);
	long long p1=0,p2=0;
	w[0]=st[0]=0;
	for(int i=mid;i>=l;i--){
		if(!st[0]||st[st[0]]!=a[i]){
			st[++st[0]]=a[i];
			p1=(p1*sd1+a[i])%md1;
			p2=(p2*sd2+a[i])%md2;
		}
		else{
			p1=(p1-a[i]+md1)*ny1%md1;
			p2=(p2-a[i]+md2)*ny2%md2;
			st[0]--;
		}
		w[++w[0]]=(p1<<31)+p2;
	}
	sort(w+1,w+w[0]+1);
	st[0]=0;
	p1=p2=0;
	for(int i=mid+1;i<=r;i++){
		if(!st[0]||st[st[0]]!=a[i]){
			st[++st[0]]=a[i];
			p1=(p1*sd1+a[i])%md1;
			p2=(p2*sd2+a[i])%md2;
		}
		else{
			p1=(p1-a[i]+md1)*ny1%md1;
			p2=(p2-a[i]+md2)*ny2%md2;
			st[0]--;
		}
		long long pp=(p1<<31)+p2;
		ans+=upper_bound(w+1,w+w[0]+1,pp)-lower_bound(w+1,w+w[0]+1,pp);
	}
	//printf("%d %d %lld\n",l,r,ans);
	return ans;
}
int main(){
int aaa=0;
	//printf("%lld\n",pw(sd,md-2));
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%lld\n",cc(1,n));
	}
}