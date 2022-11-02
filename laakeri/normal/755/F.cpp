#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int c[1010101];
int p[1010101];
int u[1010101];

int dp[1010101];
int d[1010101];

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++){
		scanf("%d", &p[i]);
	}
	int eu=0;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int x=i;
			int s=0;
			while (u[x]==0){
				u[x]=1;
				s++;
				x=p[x];
			}
			c[s]++;
			eu+=s/2;
		}
	}
	dp[0]=1;
	int up=0;
	for (int i=1;i<=n;i++){
		if (c[i]>0){
			up=up+c[i]*i;
			if (up>n) up=n;
			for (int j=0;j<=up;j++){
				if (dp[j]){
					d[j]=0;
				}
				else{
					if (j-i>=0){
						d[j]=d[j-i]+1;
					}
					else{
						d[j]=2*n;
					}
				}
				if (d[j]<=c[i]){
					dp[j]=1;
				}
			}
		}
	}
	if (k==0){
		printf("0 0\n");
		return 0;
	}
	if (dp[k]){
		printf("%d ", k);
	}
	else{
		printf("%d ", k+1);
	}
	if (k<=eu){
		printf("%d\n", k*2);
	}
	else{
		int v=eu*2;
		k-=eu;
		v+=k;
		v=min(v, n);
		printf("%d\n", v);
	}
}