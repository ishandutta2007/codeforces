#include<bits/stdc++.h>
#define N 200010
using namespace std;
char s1[N],s2[N];
int n,m,i,g[N],f[N],G[N],F[N],a,b,c,q,d;
char ans[N];
int count(int B,int A,int D,int C){
	//printf("%d %d %d %d\n",A,B,C,D);
	if(!A){
		if(!C){
			if(B>=D&&(B-D)%3==0)return 1;
			return 0;
		}
		if(B==D)return 0;
	}
	if(B<D)return 0;
	A+=2*((B-D)%3!=0);
	if(A>C||(C-A)%2)return 0;
	return 1;
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	for(i=1;i<=n;i++){
		g[i]=g[i-1];
		if(s1[i]=='A')f[i]=f[i-1]+1;
		else g[i]++;
	}
	for(i=1;i<=m;i++){
		G[i]=G[i-1];
		if(s2[i]=='A')F[i]=F[i-1]+1;
		else G[i]++;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans[i]='0'+count(min(b-a+1,f[b]),g[b]-g[a-1],min(d-c+1,F[d]),G[d]-G[c-1]);
	}
	printf("%s\n",ans);
}