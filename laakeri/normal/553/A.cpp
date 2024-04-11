#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll ncr[2020][2020];

int c[1010];

ll get(int n, int k){
    if (k==-1) return 1;
    return (ncr[n-1][c[k]-1]*get(n-c[k], k-1))%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ncr[0][0]=1;
    for (int i=1;i<2020;i++){
        ncr[i][0]=1;
        for (int ii=1;ii<2020;ii++){
            ncr[i][ii]=ncr[i-1][ii]+ncr[i-1][ii-1];
            ncr[i][ii]%=mod;
        }
    }
    int k;
    cin>>k;
    int n=0;
    for (int i=0;i<k;i++){
        cin>>c[i];
        n+=c[i];
    }
    cout<<get(n, k-1)<<endl;
}