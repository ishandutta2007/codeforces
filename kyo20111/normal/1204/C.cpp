#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,o[1010101],dist[111][111],dp[1010101],bt[1010101];
void f(int a){
	if(!a) return;
	f(bt[a]);
	printf("%d ",o[a]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%01d",&dist[i][j]);
    scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&o[i]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j && dist[i][k] && dist[k][j] && (!dist[i][j] || dist[i][j]>dist[i][k]+dist[k][j])) dist[i][j] = dist[i][k]+dist[k][j];

	for(int i=1;i<=m;i++){
		dp[i] = dp[i-1]+1;
		bt[i] = i-1;

		int j=i-1;
		for(;j>=max(i-n,1);j--){
			if(dist[o[j]][o[i]] != dist[o[j-1]][o[i]]-1) break;
		}

		if(dp[i] > dp[j]+1){
			dp[i] = dp[j]+1;
			bt[i] = j;
		}
	}
	printf("%d\n",dp[m]);
	f(m);
}