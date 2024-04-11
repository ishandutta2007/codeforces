// another fine solution by misof
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// MODEXP expects: 0<number<2^31, 0<=power<2^63, 0<modulus<2^31
// MODEXP returns: (number^power) % modulus
long long MODEXP(long long number, long long power, long long modulus) { if (power==0) return 1LL % modulus; if (power==1) return number % modulus; long long tmp = MODEXP(number,power/2,modulus); tmp = (tmp*tmp) % modulus; if (power&1) tmp = (tmp*number) % modulus; return tmp; }
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

const int MOD = 1000000007;
const int MAXK = 5010;

int **memo1, **memo2;
vector< vector<int> > cmemo;

int stirling1(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (n == k) return 1;
    if (k == 0) return 0;
    int &res = memo1[n][k];
    if (res == -1) {
        long long tmp = stirling1(n-1,k);
        tmp *= n-1;
        tmp = stirling1(n-1,k-1) - tmp;
        tmp %= MOD;
        if (tmp < 0) tmp += MOD;
        res = tmp;
    }
    return res;
}

int stirling2(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (n == 0 || k == 0) return 0;
    int &res = memo2[n][k];
    if (res == -1) {
        long long tmp;
        tmp = stirling2(n-1,k);
        tmp *= k;
        tmp += stirling2(n-1,k-1);
        tmp %= MOD;
        if (tmp < 0) tmp += MOD;
        res = tmp;
    }
    return res;
}

int POWN2[MAXK];

int coef(int k, int power) {
    int answer = 0;
    for (int j=0; j<=k; ++j) {
        long long term = 1;
        if ((k+j)%2) term = -1;
        term *= POWN2[k-j];
        term *= memo2[k][j];
        term %= MOD;
        term *= memo1[j][power];
        term %= MOD;
        if (term < 0) term += MOD;
        answer += term;
        answer %= MOD;
    }
    return answer;
}

int comb(int n, int k) {
    if (k==0 || k==n) return 1;
    int &res = cmemo[n][k];
    if (res == -1) {
        res = comb(n-1,k-1) + comb(n-1,k);
        if (res >= MOD) res -= MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    POWN2[0] = 1;
    for (int k=1; k<=5000; ++k) {
        long long tmp = POWN2[k-1];
        tmp *= (MOD-2);
        tmp %= MOD;
        POWN2[k] = tmp;
    }

    int N, K;
    cin >> N >> K;
    if (N <= 5000) {
        cmemo.resize( N+1, vector<int>(N+1,-1) );
        long long answer = 0;
        for (int n=1; n<=N; ++n) {
            answer += MODEXP(n,K,MOD) * comb(N,n);
            answer %= MOD;
        }
        cout << answer << endl;
    } else {
        memo1 = (int**)malloc( (K+1) * sizeof(int*) );
        for (int k=0; k<=K; ++k) memo1[k] = (int*)malloc( (K+1)*sizeof(int) );
        for (int k=0; k<=K; ++k) memset( memo1[k], -1, (K+1)*sizeof(int) );
        memo2 = (int**)malloc( (K+1) * sizeof(int*) );
        for (int k=0; k<=K; ++k) memo2[k] = (int*)malloc( (K+1)*sizeof(int) );
        for (int k=0; k<=K; ++k) memset( memo2[k], -1, (K+1)*sizeof(int) );

        for (int n=0; n<=K; ++n) {
            for (int k=0; k<=K; ++k) {
                {
                    if (k > n) { memo1[n][k] = 0; continue; }
                    if (n == k) { memo1[n][k] = 1; continue; }
                    if (k == 0) { memo1[n][k] = 0; continue; }
                    long long tmp = n > 0 ? memo1[n-1][k] : 0;
                    tmp *= n-1;
                    tmp = (n > 0 && k > 0 ? memo1[n-1][k-1] : 0) - tmp;
                    tmp %= MOD;
                    if (tmp < 0) tmp += MOD;
                    memo1[n][k] = tmp;
                }
            }
        }
        for (int n=0; n<=K; ++n) {
            for (int k=0; k<=K; ++k) {
                {
                    if (n == 0 && k == 0) { memo2[n][k] = 1; continue; }
                    if (n == 0 || k == 0) { memo2[n][k] = 0; continue; }
                    long long tmp;
                    tmp = (n > 0 ? memo2[n-1][k] : 0);
                    tmp *= k;
                    tmp += (n > 0 && k > 0 ? memo2[n-1][k-1] : 0);
                    tmp %= MOD;
                    if (tmp < 0) tmp += MOD;
                    memo2[n][k] = tmp;
                }
            }
        }

        long long poly = 0;
        for (int p=K; p>=0; --p) {
            poly *= N;
            poly += coef(K,p);
            poly %= MOD;
        }
        poly *= MODEXP(2,N-K,MOD);
        poly %= MOD;
        poly += MOD;
        poly %= MOD;
        cout << poly << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread