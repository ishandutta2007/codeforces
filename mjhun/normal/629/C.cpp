#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll c[2005];
ll d[2005];
char s[100005];
int n,m;
ll dp[2048][2048];

// j quedan k uso
ll f(int j, int k){
	if(j>k)return 0;
	if(dp[j][k]>=0)return dp[j][k];
	if(k==0)dp[j][k]=(j==0);
	else if(j==0)dp[j][k]=0;
	else {
		dp[j][k]=(f(j-1,k-1)+f(j+1,k-1))%MOD;
	}
	return dp[j][k];
}

int main(){
	memset(dp,-1,sizeof(dp));
	c[0]=1;
	for(int i=1;i<=2000;++i){
		for(int j=0;j<=i-1;++j)c[i]+=c[j]*c[i-1-j],c[i]%=MOD;
	}
	for(int i=0;i<=1000;++i){
		d[2*i]=((2*i+1)*c[i])%MOD;
	}
	scanf("%d%d%s",&n,&m,s);
	int a=0,b=0,k=0;
	for(int i=0;i<m;++i){
		if(s[i]=='(')k--;
		else k++;
		a=max(a,k);
	}
	k=0;
	for(int i=m-1;i>=0;--i){
		if(s[i]=='(')k++;
		else k--;
		b=max(b,k);
	}
	//printf("%d %d\n",a,b);
	ll r=0;
	for(int i=0;i<=n-m;++i){
		for(int j=0;i+j<=n-m;++j){
			r+=(((f(a,i)*f(b,j))%MOD)*d[n-m-i-j])%MOD;
			r%=MOD;
		}
	}
	cout<<r<<endl;
	return 0;
}