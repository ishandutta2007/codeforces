#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ld dp[2002][2002];

int main(){
    int n,t;
    ld p;
    cin>>n>>p>>t;
    dp[0][0]=1;
    for (int i=0;i<t;i++){
        for (int ii=0;ii<=n;ii++){
            if (ii<n){
                dp[i+1][ii+1]+=dp[i][ii]*p;
                dp[i+1][ii]+=dp[i][ii]*((ld)1-p);
            }
            else{
                dp[i+1][ii]+=dp[i][ii];
            }
        }
    }
    ld v=0;
    for (int i=0;i<=n;i++){
        v+=(ld)i*dp[t][i];
    }
    cout<<setprecision(15)<<v<<endl;
}