#include<string.h>
#include<stdio.h>
char A[1111111],pat[111111];
int nex[111111][26],suf[111111];
int n,m;
int dp[11111111];
void upd(int&x,int y){if(x==-1||x<y)x=y;}
int main(){
	scanf("%s%s",A+1,pat+1);
	n = strlen(A+1);
	m = strlen(pat+1);
	memset(nex,-1,sizeof(nex));
	for(int i=1; i<=m; i++){
		pat[i] -= 'a';
		if(i<m)nex[i-1][pat[i]] = i;
	}
	for(int j=0; j<26; j++)if(nex[0][j] == -1)nex[0][j] = 0;
	for(int i=1; i<m; i++){
		if(i==1)suf[1] = 0;else
			suf[i] = nex[suf[i-1]][pat[i]];
		for(int j=0; j<26; j++)
			if(nex[i][j] == -1)nex[i][j] = nex[suf[i]][j];
	}
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	int res=0;
	for(int i=0; i<=n; i++)
	for(int j=0,Z; j<m; j++)if((Z=dp[i*m+j])!=-1){
		if(i == n)upd(res, Z);else{
		int u = 0, d = 25;
		if(A[i+1] != '?')u = d = A[i+1]-'a';
		for(int k=u; k<=d; k++)
			upd(dp[(i+1)*m+nex[j][k]], Z + (j == m-1 && k == pat[m]?1:0));
		}
	}
	printf("%d\n",res);
	return 0;
}