#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 20;
const int L = 77;
const int MOD = 1000 * 1000 * 1000 + 7;

int f[L][1 << N];
int min_go[L];
int max_go[L];
string s;
int val[L][L];

void madd(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        f[i][0] = 1;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        min_go[i] = n;
        max_go[i] = i - 1;
        for (int j = i; j < n; j++) {
            cur = cur * 2 + s[j] - '0';
            val[i][j] = cur - 1;
            if (cur > N)
                break;
            if (cur > 0)  
                min_go[i] = min(min_go[i], j);
            max_go[i] = max(max_go[i], j);     
        }   
    }
    for (int p = 0; p < n; p++) {
        for (int m = 0; m < (1 << N); m++) {
            if (f[p][m] == 0)
                continue;
            for (int j = min_go[p]; j <= max_go[p]; j++)
                madd(f[j + 1][m | (1 << val[p][j])], f[p][m]);      
        }          
    }
    int res = 0;
    for (int m = 2; m <= (1 << N); m *= 2) {
        int mask = m - 1;
        for (int p = 0; p <= n; p++) {
            madd(res, f[p][mask]);
        }
    }
    cout << res << endl;
}