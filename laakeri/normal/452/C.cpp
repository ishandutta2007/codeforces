#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

ld dp[1003][1003];

int main(){
    int n,m;
    cin>>n>>m;
    dp[1][1]=1;
    for (int i=1;i<=n;i++){
        for (int ii=1;ii<=m;ii++){
            dp[i+1][ii+1]+=dp[i][ii]*(((ld)m-(ld)ii)/((ld)m*(ld)n-(ld)i));
            dp[i+1][ii]+=dp[i][ii]*(1-((ld)m-(ld)ii)/((ld)m*(ld)n-(ld)i));
        }
    }
    ld v=0;
    for (int i=1;i<=m;i++){
        v+=dp[n][i]*((ld)i/(ld)n);
    }
    cout<<setprecision(12)<<v<<endl;
}