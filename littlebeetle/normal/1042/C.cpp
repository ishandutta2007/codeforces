#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int a,d;
	bool operator<(const p &k)const {
		if(!k.a||!a)
			return a;
		if((k.a>0)^(a>0))
			return k.a<a;
		return k.a>a;
	}
}x[N];
int n,i,u,v;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		x[i].d=i;
		u+=x[i].a>0;
		v+=x[i].a<0;
	}
	if(v&1)v--;
	u+=v;
	sort(x+1,x+n+1);
	for(i=1;i<u;i++)
		printf("1 %d %d\n",x[i].d,x[i+1].d);
	for(i=u+1;i<n;i++)
		printf("1 %d %d\n",x[i].d,x[i+1].d);
	if(u!=n&&u!=0)
		printf("2 %d",x[n].d);
}