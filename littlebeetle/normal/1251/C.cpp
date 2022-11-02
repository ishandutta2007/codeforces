#include<cstdio>
const int N=300002;
int T,n,l1,r1,l2,r2,i,q1[N],q2[N],k;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		for(n=0;s[n+1];n++);
		l1=l2=1;r1=r2=0;
		for(i=1;i<=n;i++){
			k=s[i]-48;
			if(k%2==0)
				q1[++r1]=k;
			else
				q2[++r2]=k;
		}
		while(l1<=r1||l2<=r2){
			if(l2>r2||(l1<=r1&q1[l1]<=q2[l2]))
				printf("%d",q1[l1++]);
			else
				printf("%d",q2[l2++]);
		}
		printf("\n");
	}
}