#include<cstdio>
int main(){
	int a,n;
    scanf("%d",&n);
    long long s=0,t=0;
    while(n--){
		scanf("%d",&a);
		if(a)++t;
		else s+=t;
	}
    return printf("%lld",s),0;
}