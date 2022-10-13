#include<bits/stdc++.h>
#define ran 1111
int n,k;
char s[ran];
bool dp[ran][ran*2];
void oup(int n,int k){
	if(n==0)return;
	if((s[n-1] == 'W' || s[n-1] == '?') && dp[n-1][k-1]){
		oup(n-1,k-1);
		putchar('W');
	}else
	if((s[n-1] == 'D' || s[n-1] == '?') && dp[n-1][k]){
		oup(n-1,k);
		putchar('D');
	}else
	if((s[n-1] == 'L' || s[n-1] == '?') && dp[n-1][k+1]){
		oup(n-1,k+1);
		putchar('L');
	}
}
int main(){
	scanf("%d%d%s",&n,&k,s);
	dp[0][ran] = true;
	for(int i=0; i<n; i++){
	for(int j=ran-(k-1); j<=ran+(k-1); j++)
	if(dp[i][j]){
		if(s[i] == 'W' || s[i] == '?')dp[i+1][j+1] = true;
		if(s[i] == 'D' || s[i] == '?')dp[i+1][j] = true;
		if(s[i] == 'L' || s[i] == '?')dp[i+1][j-1] = true;
	}
	dp[i][ran-k] = dp[i][ran+k] = false;
	}
	if(dp[n][ran+k]){
		oup(n, ran+k);
		puts("");
	}
	else
	if(dp[n][ran-k]){
		oup(n, ran-k);
		puts("");
	}
	else
		puts("NO");
	return 0;
}