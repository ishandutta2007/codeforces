#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int x=1,y=3;
		for(int i=1;i<a;i++)
			x=x*10;
		for(int i=1;i<=b-c;i++)
			y=y*10+3;
		for(int i=1;i<c;i++)
			y=y*10;
		printf("%d %d\n",x,y);
	}
}