#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long double arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    long double dp[1<<n];
    int size = (1<<n)-1;
    for(int i=0;i<=size;i++) dp[i]=0.0;
    string s,p;
    int oo = 0;
    dp[size]=1.0;
    for(int k = size ;k>=1;k--){
        p = bitset<18>(k).to_string();
        oo=0;
        s=p;
        for(int i=0;i<18;i++){
            s[i]=p[17-i];
            if(s[i]=='1')   oo++;
        }
        for(int i=0;i<18;i++){
            if(s[i]=='0') continue;
            for(int j=0;j<18;j++){
                if(i==j || s[j]=='0') continue;
                dp[k-(1<<i)]+=dp[k]*arr[j][i]*(2.0/(oo*(oo-1)));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[(1<<i)]<<" ";
    }        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}