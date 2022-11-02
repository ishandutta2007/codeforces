#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, dp[30][200010], m, arr[100];
char str[200010], input[200010];
int main()
{
    scanf("%d", &n);
    scanf("%s", str+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=26; j++){
            dp[j][i]=dp[j][i-1];
        }
        int temp1=str[i]-'a'+1;
        dp[temp1][i]++;
    }
    scanf("%d", &m);
    for(int t=1; t<=m; t++){
        scanf("%s", input+1);
        for(int i=0; i<30; i++){
            arr[i]=0;
        }
        int len=strlen(input+1);
        for(int i=1; i<=len; i++){
            int temp2=input[i]-'a'+1;
            arr[temp2]++;
        }
        int ans=0;
        for(int i=1; i<=26; i++){
            ans=max(ans, lower_bound(dp[i], dp[i]+n+1, arr[i])-dp[i]);
        }
        printf("%d\n", ans);
    }
}