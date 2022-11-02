#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300002;
int n,i,lst;
struct p{
	int a,b;
	bool operator<(const p &k)const{
		if(k.a!=a)return k.a>a;
		return k.b>b;
	}
}x[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i].a,&x[i].b);
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++)
		if(x[i].b>=lst)
			lst=x[i].b;
		else
			lst=x[i].a;
	printf("%d",lst);
}