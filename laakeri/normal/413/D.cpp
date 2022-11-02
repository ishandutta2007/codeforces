#include <iostream>

using namespace std;

typedef long long ll;

ll dp[2002][(1<<12)];
int as[2002];
ll joku[2002];

int MOD=1000000007;

int main(){
    int n,k;
    cin>>n>>k;
    ll v=0;
    for (int i=0;i<n;i++){
        cin>>as[i];
    }
    ll jss=1;
    for (int i=n-1;i>=0;i--){
        joku[i]=jss;
        if (as[i]==0){
            jss*=2;
            jss%=MOD;
        }
    }
    for (int i=0;i<n;i++){
        int a=as[i];
        if (a==0){
            if (i==0){
                dp[i][2]=1;
                dp[i][4]=1;
            }
            else{
                for (int aa=2;aa<=4;aa<<=1){
                    for (int ii=0;ii<(1<<12);ii++){
                        a=aa;
                        if (dp[i-1][ii]>0){
                            //cout <<i<<" "<<ii<<" "<<dp[i-1][ii]<<endl;
                            int f=0;
                            for (int iii=2;iii<=(1<<k);iii*=2){
                                if (ii&iii) {
                                    f=iii;
                                    break;
                                }
                            }
                            if (f>a){
                                dp[i][ii|a]+=dp[i-1][ii];
                                dp[i][ii|a]%=MOD;
                            }
                            else if (f==a){
                                int ii2=ii;
                                while (ii2&a){
                                    ii2&=~a;
                                    a<<=1;
                                }
                                ii2|=a;
                                if (ii2==(1<<k)){
                                    v+=joku[i]*dp[i-1][ii];
                                    v%=MOD;
                                }
                                else{
                                    dp[i][ii2]+=dp[i-1][ii];
                                    dp[i][ii2]%=MOD;
                                }
                            }
                            else if (f<a){
                                dp[i][a]+=dp[i-1][ii];
                                dp[i][a]%=MOD;
                            }
                        }
                    }
                }
            }
        }
        else{
            if (i==0){
                dp[i][a]=1;
            }
            else{
                int aa=a;
                for (int ii=0;ii<(1<<12);ii++){
                    a=aa;
                    if (dp[i-1][ii]>0){
                        //cout <<i<<" "<<ii<<" "<<dp[i-1][ii]<<endl;
                        int f=0;
                        for (int iii=2;iii<=(1<<k);iii*=2){
                            if (ii&iii) {
                                f=iii;
                                break;
                            }
                        }
                        if (f>a){
                            dp[i][ii|a]+=dp[i-1][ii];
                            dp[i][ii|a]%=MOD;
                        }
                        else if (f==a){
                            int ii2=ii;
                            while (ii2&a){
                                ii2&=~a;
                                a<<=1;
                            }
                            ii2|=a;
                            if (ii2==(1<<k)){
                                v+=joku[i]*dp[i-1][ii];
                                v%=MOD;
                            }
                            else{
                                dp[i][ii2]+=dp[i-1][ii];
                                dp[i][ii2]%=MOD;
                            }
                        }
                        else if (f<a){
                            dp[i][a]+=dp[i-1][ii];
                            dp[i][a]%=MOD;
                        }
                    }
                }
            }
        }
    }
    cout <<v<<endl;
}