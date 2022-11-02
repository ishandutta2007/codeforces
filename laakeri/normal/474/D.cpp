#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1000000007;

ll dp[100012];
ll st[100011];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,k;
    cin>>t>>k;
    dp[0]=1;
    for (int i=0;i<=100000;i++){
        dp[i+1]+=dp[i];
        dp[i+1]%=mod;
        if (i+k<=100000) {
            dp[i+k]+=dp[i];
            dp[i+k]%=mod;
        }
    }
    for (int i=1;i<=100000;i++){
        st[i]=dp[i];
        st[i]+=st[i-1];
        st[i]%=mod;
    }
    for (int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        ll lol=st[b]-st[a-1];
        if (lol<0) lol+=mod;
        cout<<lol<<'\n';
    }
}