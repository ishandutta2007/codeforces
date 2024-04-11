#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    int L = __lg(s.length());
    int X = (1 << L) - 1;

    string answer = "";

    vector<bool> ok(1 << L, true);

    for (int pref = 0; pref < (int)s.length() - X; ++pref){

        char nxt = 'z';

        for (int i = 0; i < (1 << L); ++i){
            if (ok[i]){
                int p = pref + i;
                nxt = min(nxt, s[p]);
            }
        }

        answer += nxt;

        vector<bool> nx(1 << L); 

        for (int i = 0; i < (1 << L); ++i){
            if (!ok[i]) continue;

            int p = pref + i;

            if (s[p] == nxt)
                nx[i] = true;

            if (nx[i]){
                for (int j = 0; j < L; ++j)
                    nx[i | (1 << j)] = true;
            }
        }

        ok.swap(nx);
    }

    cout << answer << endl;

    return 0;
}