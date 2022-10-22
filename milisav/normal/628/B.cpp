#include<bits/stdc++.h>
#define maxn 400000
#define dv 4 
using namespace std;
int dp[dv];
int gp[dv];
char s[maxn];
int main() {
    scanf("%s",s);
    int n=strlen(s);
    long long ans=0;
    for(int i=0;i<n;i++) {
        int md=(s[i]-'0')%dv;
        for(int j=0;j<dv;j++) gp[j]=0;
        for(int j=0;j<dv;j++) {
            gp[(j*10+md)%dv]+=dp[j];
        }
        gp[md]+=1;
        for(int j=0;j<dv;j++) dp[j]=gp[j];
        ans=(ans+dp[0]);
    }
    printf("%lld",ans);
    return 0;
}