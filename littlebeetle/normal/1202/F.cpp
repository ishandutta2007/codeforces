#include<cstdio>
int a,b,l,r,ans,Lst,t,k;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&a,&b);
	for(l=1;l<=a+b;l=r+1){
		t=(a+b)/l;
		r=(a+b)/t;
		//printf("%d\n",a/l+b/l-(a+r)/(r+1)-(b+r)/(r+1)+1);
		if(a/t>=(a+t)/(t+1)&&b/t>=(b+t)/(t+1))
			ans+=max(min(a/t+b/t,r)-max((a+t)/(t+1)+(b+t)/(t+1),l)+1,0);
		//printf("%d %d\n",(a+r)/(r+1)+(b+r)/(r+1),a/l+b/l);
		//if(t>0)
		//	ans+=t,
		//	Lst=(a+r)/(r+1)+(b+r)/(r+1);
	}
	printf("%d",ans);
	return 0;
}