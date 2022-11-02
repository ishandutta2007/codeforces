#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

int dp[1<<21];

int chs[21];

vector<pair<char,int> > f;

int p=0;

int n,m;

int main(){
    cin>>n;
    vector<int> cc;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cc.push_back(a);
    }
    cin>>m;
    f.resize(m);
    for (int i=0;i<m;i++){
        cin>>f[i].F>>f[i].S;
        if (f[i].F=='p'){
            p++;
        }
    }
    while (f.back().F=='b'){
        f.pop_back();
        m--;
    }
    sort(cc.rbegin(), cc.rend());
    int i=0;
    for (int a:cc){
        chs[i]=a;
        i++;
        if (i==m){
            break;
        }
    }
    for (int i=1;i<(1<<m);i++){
        int ph=0;
        for (int ii=0;ii<m;ii++){
            if (i&(1<<ii)){
                //cout<<1;
                ph++;
            }
            else{
                //cout<<0;
            }
        }
        //cout<<endl;
        ph=m-ph;
        int v1=0;
        if (f[ph].S==1){
            v1=1;
        }
        dp[i]=1e9;
        for (int ii=0;ii<m;ii++){
            if (i&(1<<ii)){
                int lol=dp[i^(1<<ii)];
                if (f[ph].F=='p'){
                    if (v1){
                        lol+=chs[ii];
                    }
                    else{
                        lol-=chs[ii];
                    }
                }
                if (dp[i]==1e9){
                    dp[i]=lol;
                }
                else{
                    if (v1){
                        dp[i]=max(dp[i], lol);
                    }
                    else{
                        dp[i]=min(dp[i], lol);
                    }
                }
            }
        }
        //cout<<dp[i]<<endl;
    }
    cout<<dp[(1<<m)-1]<<endl;
}