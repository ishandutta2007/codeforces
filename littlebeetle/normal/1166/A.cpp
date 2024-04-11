#include<cstdio>
const int N=1002;
int n,i,f[N],ans,x,y;
char s[N];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		f[*s]++;
	}
	for(i=0;i<N;i++){
		x=f[i]/2;
		y=f[i]-x;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
	printf("%d",ans);
	return 0;
}