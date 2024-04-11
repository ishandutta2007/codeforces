#include<cstdio>
const int N=100002;
int w,l,a[N],s[N],ans=1<<30,i;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&w,&l);
	for(i=1;i<w;i++)
		scanf("%d",a+i),s[i]=s[i-1]+a[i];
	for(i=l;i<w;i++)
		ans=min(ans,s[i]-s[i-l]);
	printf("%d",ans);
	//while(1);
}