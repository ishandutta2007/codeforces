#include<bits/stdc++.h>
using namespace std;
long long dp[200];
long long a[200][200];
long long e[200][200];
long long b[200][200];
long long n;
int m;
long long mod=1000000007;
void step(long long k) {
	long long l=1;
	while(k>0) {
		if(k&l) {
			for(int i=0;i<m;i++) {
				for(int j=0;j<m;j++) {
					b[i][j]=0;
					for(int o=0;o<m;o++) b[i][j]=(b[i][j]+(e[i][o]*a[o][j])%mod)%mod; 
				}
			}
			for(int i=0;i<m;i++) {
				for(int j=0;j<m;j++) {
					e[i][j]=b[i][j];
				}
			}
			k-=l;
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<m;j++) {
				b[i][j]=0;
				for(int o=0;o<m;o++) b[i][j]=(b[i][j]+(a[i][o]*a[o][j])%mod)%mod; 
			}
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=b[i][j];
			}
		}
		l=l<<1;
	}
}
int main() {
	scanf("%lld %d",&n,&m);
	if(n<m) {
		printf("1");
		return 0;
	}
	for(int i=0;i<m;i++) dp[i]=1;
	a[0][0]=1;
	a[0][m-1]=1;
	for(int i=0;i<m;i++) e[i][i]=1;
	for(int i=1;i<m;i++) {
		for(int j=0;j<m;j++) if(j+1==i) a[i][j]=1;
	}
	n-=(m-1);
	step(n);
	long long r=0;
	for(int i=0;i<m;i++) r=(r+(e[0][i]*dp[i])%mod)%mod;
	printf("%lld",r);
	return 0;
}