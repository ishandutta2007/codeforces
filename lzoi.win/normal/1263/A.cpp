#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,s;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		if(a+b>=c) s=c+(a+b-c>>1);
		else s=a+b;
		printf("%d\n",s);
	}
	return 0;
}