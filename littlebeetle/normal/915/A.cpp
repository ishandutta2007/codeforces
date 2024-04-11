#include<cstdio>
int n,k,a,s;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	s=1<<30;
	while(n--){
		scanf("%d",&a);
		if(k%a==0)
			s=min(s,k/a);
	}
	printf("%d",s);
}