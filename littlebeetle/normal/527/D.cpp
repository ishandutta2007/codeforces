#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2000005;
struct tn{
	long long s,e;
}a[N];
long long l=-(1ll<<60);
long long n,i,x,w,s;
bool cmp(tn p,tn q){
	return p.e<q.e;
}
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x,&w);
		a[i].s=x-w;
		a[i].e=x+w;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		if(a[i].s>=l)
			l=a[i].e,s++;
	printf("%lld",s);
	return 0;
}