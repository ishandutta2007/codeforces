#include<cstdio>
int T,b,p,f,h,c,i,j,s;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		s=0;
		scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
		for(i=0;i<=p;i++)
			for(j=0;j<=f;j++)
				if(i*2+j*2<=b)
					s=max(s,i*h+j*c);
		printf("%d\n",s);
	}
	//while(1);
}