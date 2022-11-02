#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=200002;
int n,m,i,j,k,Tn[N],kmp[N];
char p[N],q[N],s[N],t[N];
int Ans[N];
void init(){
	scanf("%s%s",p,q);
	while(p[n])n++;
	while(q[m])m++;
	memset(Ans,0x3f,sizeof(Ans));
}
void check(int g){
	int i,j,k;
	for(i=0;i<n;i++)
		s[i]=Tn[p[i]-97]+97;
	for(i=0;i<m;i++)
		t[i]=Tn[q[i]-97]+97;
	memset(kmp,0,sizeof(kmp));
	for(i=1,k=0;i<m;i++){
		while(k&&t[i]!=t[k])
			k=kmp[k];
		if(t[i]==t[k])
			kmp[i+1]=++k;	
	}
	for(i=k=0;i<n;i++){
		while(k&&s[i]!=t[k])
			k=kmp[k];
		if(s[i]==t[k]){
			k++;
			if(k==m){
				Ans[i-m+1]=min(Ans[i-m+1],g);
				k=kmp[k];
			}
		}
	}
}
void dfs(int i,int g){
	if(i==6){
		check(g);
		return;
	}
	for(int j=0;j<=i;j++){
		Tn[i]=j;
		dfs(i+1,g+(i!=j));
	}
}
void work(){
	dfs(0,0);
	for(i=0;i<=n-m;i++)
		printf("%d ",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}