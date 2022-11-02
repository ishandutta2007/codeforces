#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int dp[102][1<<16];
int dpf[102][1<<16];
int dpv[102][1<<16];

int pmb[62];

vector<int> primes;

int main(){
    for (int i=2;i<59;i++){
        int f=0;
        for (int p:primes){
            if (i%p==0){
                f=1;
                break;
            }
        }
        if (!f){
            primes.push_back(i);
        }
    }
    for (int i=2;i<60;i++){
        int lol=i;
        for (int ii=0;ii<16;ii++){
            while (lol%primes[ii]==0) {
                pmb[i]|=(1<<ii);
                lol/=primes[ii];
            }
            if (lol==1) break;
        }
    }
    int n;
    cin>>n;
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        for (int ii=0;ii<(1<<16);ii++){
            if (dp[i][ii]){
                if (dp[i+1][ii]==0||dp[i+1][ii]>dp[i][ii]+a-1){
                    dp[i+1][ii]=dp[i][ii]+a-1;
                    dpf[i+1][ii]=ii;
                    dpv[i+1][ii]=1;
                }
                for (int iii=2;iii<2*a-1;iii++){
                    if (!(pmb[iii]&ii)){
                        int asd=pmb[iii]|ii;
                        if (dp[i+1][asd]==0||dp[i+1][asd]>dp[i][ii]+abs(a-iii)){
                            dp[i+1][asd]=dp[i][ii]+abs(a-iii);
                            dpf[i+1][asd]=ii;
                            dpv[i+1][asd]=iii;
                        }
                    }
                }
            }
        }
    }
    int mv=dp[n][0];
    int mvk=0;
    for (int i=0;i<(1<<16);i++){
        if (dp[n][i]>0&&dp[n][i]<mv){
            mv=dp[n][i];
            mvk=i;
        }
    }
    vector<int> v;
    for (int i=n;i>=1;i--){
        v.push_back(dpv[i][mvk]);
        mvk=dpf[i][mvk];
    }
    for (int i=n-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}