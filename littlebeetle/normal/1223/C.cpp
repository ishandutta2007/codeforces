#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200020;
typedef long long ll;
int Q,n,i,p[N],q[N],x,a,y,b,s[N];
int l,r,mid;
ll k,sum;
bool cmp(int x,int y){
	return x>y;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
		s[i]=0;
	scanf("%d%d%d%d",&x,&a,&y,&b);
	for(i=a;i<=n;i+=a)
		s[i]+=x;
	for(i=b;i<=n;i+=b)
		s[i]+=y;
	scanf("%lld",&k);
}
bool check(int g){
	for(i=1;i<=g;i++)
		q[i]=s[i];
	sort(q+1,q+g+1,cmp);
	sum=0;
	for(i=1;i<=g;i++)
		sum+=1ll*q[i]*p[i]/100;
	return sum>=k;
}
void work(){
	l=1;r=n+1;
	while(l<r){
		mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	if(r==n+1)
		printf("-1\n");
	else
		printf("%d\n",r);
}
int main(){
	scanf("%d",&Q);
	while(Q--){
		init();
		work();
	}
	return 0;
}