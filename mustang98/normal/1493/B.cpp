#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

string s = "0123456789";
string t = "015__2__8_";

set<string> ss;

string revs(string cur) {
    string res = cur;
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        char c = res[i];
        if (c == ':') continue;
        res[i] = t[c - '0'];
    }
    return res;
}

string getst(int i, int j) {
    string res = "";
    res += ('0' + (i / 10));
    res += ('0' + (i % 10));
    res += ':';
    res += ('0' + (j / 10));
    res += ('0' + (j % 10));
    return res;
}

void gen(int h, int m) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            ss.insert(getst(i, j));
        }
    }
}
int h, m;

void inc(int& i, int& j) {
    ++j;
    if (j == m) {
        j = 0;
        ++i;
        if (i == h) {
            i = 0;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        cin >> h >> m;
        ss.clear();
        gen(h, m);
        int i, j;
        scanf("%d:%d", &i, &j);
        //cout << h << ' ' << m << ' ' << i << ' ' << j << endl;
        while(true) {
            string rev = revs(getst(i, j));
            bool ok = true;
            for (char c : rev) {
                if (c == '_') {
                    ok = 0;
                    break;
                }
            }
            if (ok && ss.find(rev) != ss.end()) {
                cout << getst(i, j) << endl;
                break;
            }
            inc(i, j);
        }
    }

    return 0;
}