#include<cstdio>
const int N=100002;
int T,n,x,y,i;
char s[N];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		x=y=0;
		for(i=1;i<=n;i++)
			if(s[i]=='1'){
				if(!x)
					x=i;
				y=i;
			}
		if(x==0)
			printf("%d\n",n);
		else
			printf("%d\n",2*(n-min(x-1,n-y)));
	}
}