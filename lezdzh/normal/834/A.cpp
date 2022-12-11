#include<cstdio>
#define cc(c) c=='^'?0:c=='>'?1:c=='v'?2:3;
using namespace std;

int main(){
	char s[10];
	int u,v,n;
	scanf("%s",s);
	u=cc(s[0]);
	scanf("%s",s);
	v=cc(s[0]);
	scanf("%d",&n);
	printf((u+n&3)!=v?"ccw\n":(u-n&3)!=v?"cw\n":"undefined\n");
}