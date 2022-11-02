#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n, m;
string str[50010];
int dp1[50010], dp2[50020];
int main()
{
    scanf("%d", &t);
    for(int u=1; u<=t; u++){
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            cin>>str[i];
            dp1[i]=0;
            for(int j=0; j<m; j++){
                if(str[i][j]=='*')dp1[i]++;
            }
        }
        for(int i=0; i<m; i++){
            dp2[i]=0;
            for(int j=0; j<n; j++){
                if(str[j][i]=='*')dp2[i]++;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str[i][j]=='*')ans=max(ans, dp1[i]+dp2[j]-1);
                else ans=max(ans, dp1[i]+dp2[j]);
            }
        }
        printf("%d\n", n+m-1-ans);
    }

}