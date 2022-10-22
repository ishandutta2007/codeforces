#include<cstdio>
inline int max(int x,int y){
	return x>y?x:y;
}
int n,p[500001];
int main(){
	while(~scanf("%d",&n)){
		int m=-1,s=0;
		for(int i=1;i<=n;++i){
			scanf("%d",p+i);
			m=max(m,p[i]);	               
			if(m==i)m=-1,++s;
		}
		printf("%d\n",s);
	}
	return 0;
}