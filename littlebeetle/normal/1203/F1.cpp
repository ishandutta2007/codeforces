#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2002;
struct p{
	int a,b;
	bool operator<(const p &k)const{
		if(k.b*b<=0)
			return k.b<b;
		if(b>=0)
			return k.a>a;
		return k.b+k.a<b+a;
	}
}x[N];
int n,i,j,k,r,tmp;
int main(){
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i].a,&x[i].b);
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++){
		if(r>=x[i].a)
			r+=x[i].b;
		else{
			printf("NO");
			return 0;
		}
	}
	if(r<0)printf("NO");
		else
	printf("YES");
		//while(1);
}