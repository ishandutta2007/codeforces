#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 1000111222;

string s;
int gr[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int len = 1; len < max_n; ++len) {
        set<int> s;
        for (int c = 0; c < len; ++c) {
            int l = max(0, c - 1), r = max(0, len - c - 2);
            s.insert(gr[l] ^ gr[r]);
        }
        for (int i = 0; i < max_n; ++i) {
            if (s.find(i) == s.end()) {
                gr[len] = i;
                break;
            }
        }
    }
    cin >> s;
    s = "#" + s + "#";
    int x = 0;
    int cnt = 0;
    vector<pair<int, int> > lens;
    // #abacaba#
    for (int i = 1; i + 1 < s.size(); ++i) {
        if (s[i - 1] == s[i + 1]) {
            cnt++;
        } else {
            if (cnt) {
                lens.emplace_back(cnt, i - 1);
                x ^= gr[cnt];
            }
            cnt = 0;
        }
    }
    if (x == 0) {
        cout << "Second" << endl;
        return 0;
    }
    /*for (int i = 0; i < 5; ++i) {
        cout << i << ' ' << gr[i] << endl;
    }*/
    cout << "First" << endl;
    for (int i = 0; i < lens.size(); ++i) {
        int len = lens[i].F;
        for (int j = 0; j < len; ++j) {
            int xx = gr[max(0, j - 1)] ^ gr[max(0, len - j - 2)];
            for (int k = 0; k < lens.size(); ++k) {
                if (k == i) continue;
                xx ^= gr[lens[k].F];
            }
            if (xx == 0) {
                cout << lens[i].S - lens[i].F + j + 1 << endl;
                return 0;
            }
        }
    }
    exit(228);
    return 0;
}