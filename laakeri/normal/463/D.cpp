#include <iostream>

using namespace std;

int dp[1002];

int lol[1002][5];

int l[1002][5];

int has[1002][1002][5];

int used[1002];

int main(){
    int n,k;
    cin>>n>>k;
    int v=1;
    for (int i=0;i<k;i++){
        for (int ii=0;ii<n;ii++){
            cin>>lol[ii][i];
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<k;ii++){
            has[i][lol[i][ii]][ii]++;
            l[lol[i][ii]][ii]=i;
        }
        for (int ii=0;ii<k;ii++){
            int h=0;
            for (int iii=0;iii<k;iii++){
                h+=has[i][lol[i][ii]][iii];
            }
            if (h==k&&used[lol[i][ii]]==0){
                used[lol[i][ii]]=1;
                //cout<<i<<" a "<<lol[i][ii]<<endl;
                int e=dp[lol[i][ii]];
                for (int iii=1;iii<=n;iii++){
                    int hh=0;
                    for (int iiii=0;iiii<k;iiii++){
                        hh+=has[l[lol[i][ii]][iiii]][iii][iiii];
                    }
                    if (hh==0){
                        //cout<<i<<" "<<lol[i][ii]<<" "<<iii<<endl;
                        dp[iii]=max(dp[iii], e+1);
                        v=max(v, dp[iii]+1);
                    }
                }
            }
        }
        for (int ii=1;ii<=n;ii++){
            for (int iii=0;iii<k;iii++){
                has[i+1][ii][iii]+=has[i][ii][iii];
            }
        }
    }
    cout<<v<<endl;
}