#include<cstdio>
#include<algorithm>
using namespace std;

int ck(int x,int y){
	return (x>0)*4+(y>0)*2;
}
int main(){
	int n,ax,ay,bx,by,cx,cy;
	scanf("%d%d%d%d%d%d%d",&n,&ax,&ay,&bx,&by,&cx,&cy);
	printf(ck(ax-bx,ay-by)==ck(ax-cx,ay-cy)?"YES\n":"NO\n");
}