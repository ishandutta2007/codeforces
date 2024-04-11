#include<cstdio>
const int N=1000002;
int T,n,m,i,j,k,kmp[N];
char t[N],s[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%s",&T,t);
	for(m=-1;t[m+1];m++);
	while(--T){
		scanf("%s",s);
		for(n=-1;s[n+1];kmp[++n]=0);
		for(i=1,k=0;i<=n;i++){
			while(k&&s[i]!=s[k])
				k=kmp[k];
			if(s[i]==s[k])
				kmp[i+1]=++k;
		}
		for(i=max(0,m-n),k=0;i<=m;i++){
			while(k&&t[i]!=s[k])
				k=kmp[k];
			if(t[i]==s[k])
				k++;
		}
		for(j=k;j<=n;j++)
			t[i+j-k]=s[j];
		m+=n-k+1;
	}
	printf("%s",t);
}