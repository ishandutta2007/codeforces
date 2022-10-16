#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <vector <pair<ll,ll> > > dp(50,vector <pair<ll,ll> > (50));
string t;

ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    return a*pwr(a,b-1);
}

void trace_path(ll i,ll j){
    //cout<<i<<" "<<j<<endl;
    if(i==0&&j==0){
        return;
    }
    else{
        if(dp[i][j].first==dp[i][j-1].first&&j){
            t.push_back('M');
            trace_path(i,j-1);
        }
        else{
            t.push_back('H');
            trace_path(i-1,j);
        }
    }
}
int main(){
    //freopen("spam.out","w",stdout);
    ll n;cin >> n;
    string s;cin >> s;
    dp[0][0]=make_pair(0,0);
    for(ll j=1;j<=n;j++){
        dp[0][j].second+=dp[0][j-1].second+(s[2*n-j]-'0')*pwr(10,j-1);
    }
    for(ll i=1;i<=n;i++){
        dp[i][0].first+=dp[i-1][0].first+(s[2*n-i]-'0')*pwr(10,i-1);

    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll MAX=0;
            MAX=max(dp[i][j-1].second+(s[2*n-i-j]-'0')*pwr(10,j-1)+dp[i][j-1].first,dp[i-1][j].first +(s[2*n-i-j]-'0')*pwr(10,i-1)+dp[i-1][j].second);
            if(MAX==dp[i][j-1].second+(s[2*n-i-j]-'0')*pwr(10,j-1)+dp[i][j-1].first){
                dp[i][j].second= dp[i][j-1].second+(s[2*n-i-j]-'0')*pwr(10,j-1);
                dp[i][j].first = dp[i][j-1].first;
            }
            else{
                dp[i][j].first = dp[i-1][j].first +(s[2*n-i-j]-'0')*pwr(10,i-1);
                dp[i][j].second= dp[i-1][j].second;
            }
        }
    }
    /*for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            cout << dp[i][j].first << "-" << dp[i][j].second << " ";
        }
        cout << endl;
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            cout << trace_back[i][j] << " ";
        }
        cout << endl;
    }*/
    trace_path(n,n);
    cout<<t;
}