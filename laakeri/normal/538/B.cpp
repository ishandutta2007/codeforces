#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int dp[2010101];
int f[2010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> qb;
    for (int i=1;i<=1000000;i++){
        int x=i;
        int f=0;
        while (x>0){
            if (x%10>1){
                f=1;
                break;
            }
            x/=10;
        }
        if (f==0){
            qb.push_back(i);
        }
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int x:qb){
            if (dp[i]+1<dp[i+x]||dp[i+x]==0){
                dp[i+x]=dp[i]+1;
                f[i+x]=x;
            }
        }
    }
    cout<<dp[n]<<endl;
    while (n){
        cout<<f[n]<<" ";
        n-=f[n];
    }
}