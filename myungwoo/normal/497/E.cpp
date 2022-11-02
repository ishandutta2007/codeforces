#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
typedef long long lld;

const int MOD = 1e9+7;
lld N; int K;

struct MAT{
    int m[31][31];

    MAT operator * (const MAT &ot)const{
        MAT ret = {0, };
        for (int i=0;i<=K;i++) for (int j=0;j<=K;j++){
            ret.m[i][j] = 0;
            for (int k=0;k<=K;k++){
                ret.m[i][j] = (ret.m[i][j]+(lld)m[i][k]*ot.m[k][j])%MOD;
            }
        }
        return ret;
    }
} A[65][30], P[65][30], S[65][30], res;

int main()
{
    cin >> N >> K;
    vector <int> base_k;
    for (;N;N/=K) base_k.push_back(N%K);
    for (int i=0;i<K;i++){
        for (int j=0;j<=K;j++) A[0][i].m[j][j] = 1;
        for (int j=0;j<=K;j++) A[0][i].m[i][j] = 1;
    }
    for (int i=1;i<sz(base_k);i++){
        P[i-1][0] = A[i-1][0];
        for (int j=1;j<K;j++) P[i-1][j] = P[i-1][j-1]*A[i-1][j];
        S[i-1][K-1] = A[i-1][K-1];
        for (int j=K-1;j--;) S[i-1][j] = A[i-1][j]*S[i-1][j+1];
        for (int j=0;j<K;j++){
            A[i][j] = S[i-1][j];
            if (j) A[i][j] = A[i][j]*P[i-1][j-1];
        }
    }
    int x = 0;
    for (int i=0;i<=K;i++) res.m[i][i] = 1;
    for (int i=sz(base_k);i--;){
        for (int j=0;j<base_k[i];j++){
            res = res * A[i][x];
            x = (x+1)%K;
        }
    }
    int ans = 0;
    for (int i=0;i<=K;i++) ans = (ans+res.m[i][K])%MOD;
    cout << ans << endl;
}