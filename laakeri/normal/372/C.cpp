#include <iostream>
#include <cstdlib>
#include <queue>
#define F first
#define S second

using namespace std;

typedef long long ll;

int dp[303][150013];

int main(){
    ll n,m,d;
    cin>>n>>m>>d;
    ll s=0;
    ll et=0;
    for (int i=0;i<m;i++){
        ll a,b,t;
        cin>>a>>b>>t;
        ll dd=t-et;
        s+=b;
        if (i==0){
            for (ll ii=1;ii<=n;ii++){
                dp[0][ii]=abs(ii-a);
            }
        }
        else{
            deque<pair<int,ll> > mins;
            for (ll ii=1;ii<=n;ii++){
                while (!mins.empty()){
                    if (mins.back().F>=dp[i-1][ii]){
                        mins.pop_back();
                    }
                    else{
                        break;
                    }
                }
                mins.push_back(make_pair(dp[i-1][ii], ii));
                while (!mins.empty()){
                    if (mins.front().S<=ii-(d*dd*(ll)2+(ll)1)){
                        mins.pop_front();
                    }
                    else{
                        break;
                    }
                }
                int mi=mins.front().F;
                if (ii-d*dd>0){
                    dp[i][ii-d*dd]=mi+abs((ii-d*dd)-a);
                    //cout<<"1 "<<dp[i][ii-d*dd]<<" "<<i<<" "<<ii<<endl;
                }
            }
            for (ll ii=max(n+(ll)1-d*dd,(ll)1);ii<=n;ii++){
                while (!mins.empty()){
                    if (mins.front().S<=ii-(d*dd+(ll)1)){
                        mins.pop_front();
                    }
                    else{
                        break;
                    }
                }
                int mi=mins.front().F;
                dp[i][ii]=mi+abs(ii-a);
                //cout<<"2 "<<dp[i][ii]<<" "<<i<<" "<<ii<<endl;
            }
        }
        et=t;
    }
    int mi=dp[m-1][1];
    for (int i=1;i<=n;i++){
        mi=min(mi, dp[m-1][i]);
    }
    cout<<s-(ll)mi<<endl;
}