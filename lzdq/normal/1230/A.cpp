#include<cstdio>
int a1,a2,a3,a4,k;
bool flag;
int main(){
	scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
	k=a1+a2+a3+a4>>1;
	if((k<<1)!=(a1+a2+a3+a4)){
	    puts("NO");
	    return 0;
	}
	if(a1==k||a2==k||a3==k||a4==k) flag=1;
	if(a1+a2==k||a1+a3==k||a1+a4==k) flag=1;
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}