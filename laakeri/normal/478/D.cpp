#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1000000007;

ll dp[2][200001];

int main(){
    ll r, g;
    cin>>r>>g;
    if (r>g) swap(r, g);
    ll h=r+g;
    ll s=0;
    for (ll i=1;i<1000;i++){
        s+=i;
        if (s==h){
            h=i;
            break;
        }
        else if(s>h){
            h=i-1;
            break;
        }
    }
    dp[1][r]=1;
    dp[1][r-1]=1;
    ll y=0;
    for (ll i=1;i<h;i++){
        y+=i;
        for (ll hr=0;hr<=r;hr++){
            ll hg=g-(y-(r-hr));
            //cout<<i<<" "<<hr<<" "<<hg<<" "<<dp[i][hr]<<endl;
            if (hg>=0&&hg<=g){
                if (hr-(i+1)>=0) {
                    dp[(i+1)%2][hr-i-1]+=dp[i%2][hr];
                    dp[(i+1)%2][hr-i-1]%=mod;
                }
                if (hg-(i+1)>=0) {
                    dp[(i+1)%2][hr]+=dp[i%2][hr];
                    dp[(i+1)%2][hr]%=mod;
                }
            }
            dp[i%2][hr]=0;
        }
    }
    ll su=0;
    for (int i=0;i<=r;i++){
        su+=dp[h%2][i];
        su%=mod;
    }
    cout<<su<<endl;
}