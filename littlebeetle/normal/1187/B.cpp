#include<cstdio>
const int N=200002,M=26;
char s[N];
int n,q,i,j,S[N][M],T[M],tmp,l,r,mid;
void init(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++){
		for(j=0;j<M;j++)
			S[i][j]=S[i-1][j];
		S[i][s[i]-97]++;
	}
}
void work(){
	scanf("%d",&q);
	while(q--){
		scanf("%s",s+1);
		for(j=0;j<M;j++)
			T[j]=0;
		for(i=1;s[i];i++)
			T[s[i]-97]++;
		l=1;r=n;
		while(l<r){
			mid=l+r>>1;
			tmp=1;
			for(j=0;j<26;j++)
				if(S[mid][j]<T[j])
					tmp=0;
			if(tmp)
				r=mid;
			else
				l=mid+1;
		}
		printf("%d\n",r);
	}
	//while(1);
}
int main(){
	init();
	work();
}