#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int a,b;
		scanf("%d%d",&a,&b);
		if((a+b)%2)printf("-1\n");
		else if(a==b&&a==0)printf("0\n");
		else if(a==b||a==-b)printf("1\n");
		else printf("2\n");
	}
}