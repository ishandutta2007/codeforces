#include<bits/stdc++.h>
using namespace std;
int l[4];
char ct[4][2000];
int n,q;
char s[300000];
bool tkn[300000];
int sl[300000][26];
int c[26];
int dp[251][251][251];
int ans(int j,char s) {
	j--;
	if(j>=n) return n;
	if(j==-1) return c[s-'a'];
	else return sl[j][s-'a'];
}
int main()
{
	scanf("%d %d",&n,&q);
	scanf("%s",s);
	for(int i=0;i<26;i++) c[i]=n;
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<26;j++) sl[i][j]=c[j];
		c[s[i]-'a']=i;
	}
	char u[2];
	char lt[2];
	int num;
	for(int i=0;i<251;i++) {
		for(int j=0;j<251;j++) {
			for(int k=0;k<251;k++) dp[i][j][k]=n+1;
		}
	}
	dp[0][0][0]=0;
	while(q--) {
		scanf("%s",u);
		if(u[0]=='+') {
			scanf("%d %s",&num,lt);
			ct[num][l[num]++]=lt[0];
			if(num==1) {
				for(int i=0;i<=l[2];i++) {
					for(int j=0;j<=l[3];j++) {
						dp[l[1]][i][j]=min(ans(dp[l[1]-1][i][j],lt[0])+1,min((i>0 ? ans(dp[l[1]][i-1][j],ct[2][i-1])+1 : n+1),(j>0 ? ans(dp[l[1]][i][j-1],ct[3][j-1])+1 : n+1)));
					}
				}
			}
			if(num==2) {
				for(int i=0;i<=l[1];i++) {
					for(int j=0;j<=l[3];j++) {
						dp[i][l[2]][j]=min(ans(dp[i][l[2]-1][j],lt[0])+1,min((i>0 ? ans(dp[i-1][l[2]][j],ct[1][i-1])+1 : n+1),(j>0 ? ans(dp[i][l[2]][j-1],ct[3][j-1])+1 : n+1)));
					}
				}
			}
			if(num==3) {
				for(int i=0;i<=l[1];i++) {
					for(int j=0;j<=l[2];j++) {
						dp[i][j][l[3]]=min(ans(dp[i][j][l[3]-1],lt[0])+1,min((i>0 ? ans(dp[i-1][j][l[3]],ct[1][i-1])+1 : n+1),(j>0 ? ans(dp[i][j-1][l[3]],ct[2][j-1])+1 : n+1)));
					}
				}
			}
		}
		else {
			scanf("%d",&num);
			l[num]--;
		}
		if(dp[l[1]][l[2]][l[3]]<=n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}