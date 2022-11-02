#include<cstdio>
const int N=500002,K=400;
int q,x,y,t,i,s,a[N],S[K][K];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			a[x]+=y;
			for(i=1;i<K;i++)
				S[i][x%i]+=y;
		}
		else{
			if(x<K)
				printf("%d\n",S[x][y]);
			else{
				s=0;
				for(i=y;i<N;i+=x)
					s+=a[i];
				printf("%d\n",s);
			}
		}
	}
}