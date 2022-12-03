#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
const int maxm=(1<<20)+10;

int n;
char s[22][maxn];
int a[22][maxn],num[22],ned[22];
int dp[maxm][2],pre[maxm],oks[maxm];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]);
		int nw=0,lk=0;
		for (int j=0;s[i][j]!='\0';j++){
			if (s[i][j]=='(') lk--;
			else{
				lk++;
				nw=max(nw,lk);
				if (nw==lk) a[i][lk]++;
			}
		}
		num[i]=-lk;
		ned[i]=nw;
	}
	oks[0]=1;
	for (int i=1;i<(1<<n);i++){
		for (int j=0;j<n;j++){
			if (!(i&(1<<j))) continue;
			int k=i^(1<<j);
			pre[i]=pre[k]+num[j+1];
			dp[i][1]=max(dp[i][1],dp[k][1]);
			if (!oks[k]) continue;
			int h=pre[k]>=ned[j+1] ? 0:1;
			dp[i][h]=max(dp[i][h],dp[k][0]+a[j+1][pre[k]]);
			if (h==0) oks[i]=1;
		}
	}
	printf("%d\n",max(dp[(1<<n)-1][0],dp[(1<<n)-1][1]));
	return 0;
}