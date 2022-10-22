#include<cstdio>
int x,y;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(x>3) puts("YES");
		else if(x==2&&y==3||x>=y) puts("YES");
		else puts("NO");
	}
	return 0;
}