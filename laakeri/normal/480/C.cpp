#include <iostream>

using namespace std;

typedef long long ll;

ll dp[5011][5011];

ll st[5011];

ll mod=1000000007;

ll sum(int a, int b){
    if (b<a) return 0;
    if (a==0) return st[b];
    ll lol=st[b]-st[a-1];
    if (lol<0) lol+=mod;
    lol%=mod;
    return lol;
}

int main(){
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    for (int i=1;i<=k;i++){
        st[0]=0;
        for (int ii=1;ii<=n;ii++){
            st[ii]=st[ii-1];
            st[ii]+=dp[i-1][ii];
            st[ii]%=mod;
        }
        for (int ii=1;ii<=n;ii++){
            if (ii<b){
                int hw;
                if ((b+ii)%2==0) {
                    hw=(b+ii)/2-1;
                }
                else{
                    hw=(b+ii)/2;
                }
                dp[i][ii]+=sum(1, ii-1);
                dp[i][ii]%=mod;
                dp[i][ii]+=sum(ii+1, hw);
                dp[i][ii]%=mod;
            }
            if (ii>b){
                int hw;
                if ((b+ii)%2==0){
                    hw=(b+ii)/2+1;
                }
                else{
                    hw=(b+ii)/2+1;
                }
                dp[i][ii]+=sum(ii+1, n);
                dp[i][ii]%=mod;
                dp[i][ii]+=sum(hw, ii-1);
                dp[i][ii]%=mod;
            }
        }
    }
    ll su=0;
    for (int i=1;i<=n;i++){
        su+=dp[k][i];
        su%=mod;
    }
    cout<<su<<endl;
}