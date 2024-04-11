#include <iostream>

using namespace std;

int dp[2002][2002];//min hyppyj, mik i, montako kirjainta

int nc[2002][30];

int mv[2003];

int main(){
    string s,p;
    cin>>s>>p;
    int n=s.size();
    int k=p.size();
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int c=0;c<30;c++){
            nc[i][c]=-1;
            for (int ii=i;ii<n;ii++){
                if (s[ii]-'a'==c){
                    nc[i][c]=ii;
                    break;
                }
            }
        }
    }
    for (int i=0;i<=n;i++){
        for (int ii=0;ii<=n;ii++){
            if (dp[i][ii]>0){
                mv[dp[i][ii]]=max(mv[dp[i][ii]], ii);
                if (i<n){
                    int nci=nc[i][p[ii%k]-'a'];
                    if (nci>-1){
                        if (dp[nci+1][ii+1]==0||dp[nci+1][ii+1]>dp[i][ii]+nci-i){
                            dp[nci+1][ii+1]=dp[i][ii]+nci-i;
                        }
                    }
                    if (dp[i+1][ii-ii%k]==0||dp[i+1][ii-ii%k]>dp[i][ii]){
                        dp[i+1][ii-ii%k]=dp[i][ii];
                    }
                }
            }
        }
    }
    int mmv=0;
    for (int i=1;i<=n;i++){
        mmv=max(mv[i], mmv);
        cout<<min(mmv/k, (n-i+1)/k)<<" ";
    }
    cout<<0<<endl;
}