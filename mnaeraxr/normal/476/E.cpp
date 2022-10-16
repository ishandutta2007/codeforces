#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 2010;

int dp[maxn][maxn];
int beg[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    cin >> s >> p;

    int S = (int)s.length(), P = (int)p.length();

    for (int i = 0; i < S; ++i){
        int pnt = P - 1;
        beg[i + 1] = -1;

        for (int j = i; ~j; --j){
            if (s[j] == p[pnt]){
                pnt--;
                if (pnt == -1){
                    beg[i + 1] = j;
                    break;
                }
            }
        }
    }

    for (int i = 0; i <= S; ++i)
        for (int j = i + 1; j <= S; ++j)
            dp[i][j] = -oo;

    for (int i = 1; i <= S; ++i){
        for (int k = 0; k <= i; ++k){
            dp[i][k] = max(0, dp[i - 1][k]);

            if (beg[i] != -1){
                int total = i - beg[i];
                int rem = total - P;

                if (k >= rem){
                    dp[i][k] = max(dp[i][k], dp[ beg[i] ][ k - rem ] + 1);
                }
            }
        }
    }

    for (int i = 0; i <= S; ++i)
        cout << dp[S][i] << " ";
    cout << endl;

    return 0;
}

/*
mxxamaxmaxxma
mama
 */