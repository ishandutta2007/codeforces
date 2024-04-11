#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int x[200005];
ll dp[200005];
ll sp[200005];

ll f(int k){
    if(dp[k]>=0)return dp[k];
    return max(x[k]+f(k+1),-sp[k]-x[k]-f(k+1));
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",x+i),sp[i+1]=sp[i]+x[i];
    memset(dp,-1,sizeof(dp));
    dp[n]=0;
    printf("%I64d\n",x[0]+x[1]+f(2));
	return 0;
}