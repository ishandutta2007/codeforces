#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
int n,s;
int main(){
	scanf("%d%d",&n,&s);
	if(n*2>s) return puts("NO"),0;
	puts("YES");
	for(int i=1;i<n;i++) printf("2 ");
	printf("%d\n",s-n*2+2);
	puts("1");
	return 0;
}