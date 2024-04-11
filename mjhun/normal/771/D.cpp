#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
int dp[80][80][80][2];
char s[80];
int sv[80],sk[80],so[80];
int pv[80],pk[80],po[80];
int nv,nk,no;

int main(){
	scanf("%d%s",&n,s);
	fore(i,0,n){
		sv[i+1]=sv[i];
		sk[i+1]=sk[i];
		so[i+1]=so[i];
		if(s[i]=='V')pv[nv++]=i,sv[i+1]++;
		else if(s[i]=='K')pk[nk++]=i,sk[i+1]++;
		else po[no++]=i,so[i+1]++;
	}
	fore(v,0,nv+1)fore(k,0,nk+1)fore(o,0,no+1)fore(i,0,2)dp[v][k][o][i]=1<<20;
	dp[0][0][0][0]=0;
	fore(v,0,nv+1)fore(k,0,nk+1)fore(o,0,no+1)fore(i,0,2){
		int z=dp[v][k][o][i];
		if(v<nv){
			int r=z;
			int p=pv[v];
			r+=max(sk[p]-k,0)+max(so[p]-o,0);
			dp[v+1][k][o][1]=min(dp[v+1][k][o][1],r);
		}
		if(k<nk&&!i){
			int r=z;
			int p=pk[k];
			r+=max(sv[p]-v,0)+max(so[p]-o,0);
			dp[v][k+1][o][0]=min(dp[v][k+1][o][0],r);
		}
		if(o<no){
			int r=z;
			int p=po[o];
			r+=max(sk[p]-k,0)+max(sv[p]-v,0);
			dp[v][k][o+1][0]=min(dp[v][k][o+1][0],r);
		}
	}
	printf("%d\n",min(dp[nv][nk][no][0],dp[nv][nk][no][1]));
	return 0;
}