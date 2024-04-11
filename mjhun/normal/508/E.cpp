#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
int dp[605][605];
int l[605],r[605];

void pt(int i, int c){
	if(!c)return;
	putchar('(');
	fore(c0,l[i]/2,min((r[i]-1)/2,c-1)+1){
		if(dp[i+1][c0]&&dp[i+1+c0][c-1-c0]){
			pt(i+1,c0);
			putchar(')');
			pt(i+1+c0,c-1-c0);
			return;
		}
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d",l+i,r+i);
	memset(dp,-1,sizeof(dp));
	fore(i,0,n+1)dp[i][0]=1;
	fore(c,1,n+1){
		fore(i,0,n-c+1){
			dp[i][c]=0;
			fore(c0,l[i]/2,min((r[i]-1)/2,c-1)+1){
				if(dp[i+1][c0]&&dp[i+1+c0][c-1-c0]){
					dp[i][c]=1;
					break;
				}
			}
		}
	}
	if(dp[0][n]){
		pt(0,n);puts("");
	}
	else puts("IMPOSSIBLE");
	return 0;
}