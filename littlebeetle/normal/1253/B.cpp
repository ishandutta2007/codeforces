#include<cstdio>
const int N=1000002;
int n,s,i,j,k,p[N],a,Ans[N],pre[N],cnt=1;
int main(){
	scanf("%d",&n);
	while(n--){
		k++;
		scanf("%d",&a);
		if(a>0){
			if(p[a]==1||pre[a]==cnt){
				printf("-1");
				return 0;
			}
			p[a]=1;
			s++;
			pre[a]=cnt;
		}
		else{
			a=-a;
			if(p[a]==0){
				printf("-1");
				return 0;
			}
			p[a]=0;
			s--;
		}
		if(s==0){
			Ans[++cnt]=k;
			k=0;
		}
	}
	if(s){
		printf("-1");
		return 0;
	}
	printf("%d\n",cnt-1);
	for(i=2;i<=cnt;i++)
		printf("%d ",Ans[i]);
	//while(1);
	return 0;
}