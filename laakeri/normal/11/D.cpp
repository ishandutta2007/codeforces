#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> g[20];

ll dp[1<<20][20];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<n;i++){
        dp[1<<i][i]=1;
    }
    ll v=0;
    for (int i=0;i<(1<<n);i++){
        int f=0;
        int ff=0;
        for (int ii=0;ii<n;ii++){
            if ((1<<ii)&i){
                ff++;
                if (ff==1){
                    f=ii;
                    continue;
                }
                for (int nx:g[ii]){
                    dp[i][ii]+=dp[i-(1<<ii)][nx];
                }
            }
        }
        if (ff>=3){
            for (int ii=0;ii<n;ii++){
                int fff=0;
                for (int nx:g[ii]){
                    if (nx==f) {
                        fff=1;
                        break;
                    }
                }
                if (fff){
                    v+=dp[i][ii];
                }
            }
        }
    }
    cout<<v/2<<endl;
}