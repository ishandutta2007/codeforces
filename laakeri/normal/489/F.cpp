#include <iostream>

using namespace std;

typedef long long ll;

int su[501];

ll dp[2][501][501];

int main(){
    int n,m;
    ll mod;
    cin>>n>>m>>mod;
    for (int i=0;i<m;i++){
        string s;
        cin>>s;
        for (int ii=0;ii<s.size();ii++){
            if (s[ii]=='1'){
                su[ii]++;
            }
        }
    }
    int l1=0;
    int l2=0;
    for (int i=0;i<n;i++){
        if (su[i]==0){
            l2++;
        }
        if (su[i]==1){
            l1++;
        }
    }
    m=n-m;
    if (l1+l2*2!=m*2){
        cout<<0<<endl;
        return 0;
    }
    dp[0][l1][l2]=1;
    for (int i=0;i<m;i++){
        int ni=(i+1)%2;
        int ti=i%2;
        for (int ii=0;ii<501;ii++){
            for (int iii=0;iii<501;iii++){
                dp[ni][ii][iii]=0;
            }
        }
        for (int ii=0;ii<501;ii++){
            for (int iii=0;iii<501;iii++){
                if (dp[ti][ii][iii]){
                    //cout<<i<<" "<<ii<<" "<<iii<<" "<<dp[i][ii][iii]<<endl;
                    int j=m-i-1;


                    if (iii>=2){
                        ll v=(iii*(iii-1ll))/2ll;
                        v%=mod;
                        dp[ni][ii+2][iii-2]+=dp[ti][ii][iii]*v;
                        dp[ni][ii+2][iii-2]%=mod;
                    }
                    if (iii>j*2+1) break;//pakko valita 2*2

                    if (iii>=1&&ii>=1){
                        ll v=iii*ii;
                        v%=mod;
                        dp[ni][ii][iii-1]+=dp[ti][ii][iii]*v;
                        dp[ni][ii][iii-1]%=mod;
                    }
                    if (iii>j*2) break;//pakko valita vh 1*2

                    if (ii>=2){
                        ll v=(ii*(ii-1ll))/2ll;
                        v%=mod;
                        dp[ni][ii-2][iii]+=dp[ti][ii][iii]*v;
                        dp[ni][ii-2][iii]%=mod;
                    }
                }
            }
        }
    }
    cout<<dp[m%2][0][0]<<endl;
}