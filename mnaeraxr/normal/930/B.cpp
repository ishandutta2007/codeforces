#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int freq[26];
int A[26][6000][26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int l = (int)s.length();

    s += s;

    for (int i = 0; i < l; ++i){
        int u = s[i] - 'a';
        freq[u]++;
    }

    for (int i = 0; i < l; ++i){
        int u = s[i] - 'a';

        for (int j = 0; j < l; ++j){
            int v = s[i + j] - 'a';
            A[u][j][v]++;
        }
    }

    double answer = 0.;

    for (int i = 0; i < 26; ++i){
        int best = 0;
        for (int j = 0; j < l; ++j){
            int cur = 0;
            for (int k = 0; k < 26; ++k)
                if (A[i][j][k] == 1)
                    cur++;
            best = max(cur, best);
        }

        answer += 1. * best / l;
    }

    cout.precision(17);
    cout << fixed << answer << endl;

    return 0;
}