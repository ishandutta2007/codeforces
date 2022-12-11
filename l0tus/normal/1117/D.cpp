#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
const long long MOD  = 1e9+7;
long long N,M,K,A[MAX][MAX],S[MAX][MAX],sum,cnt,val,res,ans,B[MAX][MAX];
bool check;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    A[0][0] = 1;
    A[0][M-1] = 1;
    for(int i=1; i<M; i++) {
        A[i][i-1] = 1;
    }
    for(int i=0; i<M; i++) {
        S[i][i] = 1;
    }
    while(N) {
        if(N%2) {
            for(int i=0; i<M; i++) {
                for(int j=0; j<M; j++) {
                    cnt = 0;
                    for(int k=0; k<M; k++) {
                        cnt += A[i][k]*S[k][j];
                        cnt%=MOD;
                    }
                    B[i][j] = cnt%MOD;
                }
            }
            for(int i=0; i<M; i++)
                for(int j=0; j<M; j++)
                    S[i][j] = B[i][j];
        }
        for(int i=0; i<M; i++) {
            for(int j=0; j<M; j++) {
                cnt = 0;
                for(int k=0; k<M; k++) {
                    cnt += A[i][k]*A[k][j];
                    cnt%=MOD;
                }
                B[i][j] = cnt%MOD;
            }
        }
        for(int i=0; i<M; i++)
            for(int j=0; j<M; j++)
                A[i][j] = B[i][j];
        N/=2;
    }
    cout << S[0][0];
}