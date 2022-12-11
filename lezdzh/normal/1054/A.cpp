#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int x,y,z,t1,t2,t3;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	if(abs(x-y)*t1<abs(x-z)*t2+t3+t3+abs(x-y)*t2+t3)
		printf("NO\n");
	else printf("YES\n");
}