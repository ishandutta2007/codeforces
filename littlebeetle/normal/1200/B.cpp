#include<cstdio>
const int N=1002;
int T,n,m,k,h[N],i,tmp;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		tmp=1;
		for(i=1;i<=n;i++)
			scanf("%d",h+i);
		for(i=1;i<n;i++){
			if(h[i]>=max(h[i+1]-k,0))
				m+=h[i]-max(h[i+1]-k,0);
			else{
				if(h[i+1]-k-h[i]>m){
					tmp=0;
					break;
				}
				m-=h[i+1]-k-h[i];
			}
		}
		printf("%s\n",tmp?"YES":"NO");
	}
	//while(1);
}