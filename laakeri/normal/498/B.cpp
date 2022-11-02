#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dp[2][5001];

double p[5001];
int ts[5001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        cin>>p[i]>>ts[i];
        p[i]/=100.0;
    }
    double v=0;
    for (int i=1;i<=n;i++){
        for (int ii=0;ii<=t;ii++){
            dp[i%2][ii]=0;
        }
        double lol=pow((1.0-p[i-1]), (double)(ts[i-1]-1));
        double vv=0;
        for (int ii=1;ii<=t;ii++){
            if (ii>=ts[i-1]){
                dp[i%2][ii]+=lol*dp[(i-1)%2][ii-ts[i-1]];
                vv-=lol*dp[(i-1)%2][ii-ts[i-1]];
            }
            vv+=dp[(i-1)%2][ii-1];
            dp[i%2][ii]+=vv*p[i-1];
            vv-=vv*p[i-1];
            if (t==ii||i==n){
                v+=(double)i*dp[i%2][ii];
            }
            //cout<<dp[i%2][ii]<<" "<<i<<" "<<ii<<endl;
        }
        v+=(double)(i-1)*vv;
    }
    cout<<setprecision(15)<<v<<endl;
}