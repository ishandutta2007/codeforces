#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

string next(string s) {
    int cur = 0;
    for(int i = (int)s.size() - 1;i >= 0;i--) {
        if(s[i] == '9') {
            cur += 9;
            continue;
        }
        if(cur == 0) {
            cur += s[i] - '0';
            continue;
        }
        s[i]++;
        cur--;
        int j = (int)s.size() - 1;
        while(cur >= 9) {
            s[j] = '9';
            j--;
            cur -= 9;
        }
        s[j] = cur + '0';
        for(int q = i + 1;q < j;q++) {
            s[q] = '0';
        }
        return s;
    }
    string res((int)s.size() + 1, '0');
    cur = 0;
    for(int i = 0;i < (int)res.size();i++) {
        for(int x = i == 0;x < 10;x++) {
            int tmp = 10 - cur - x;
            if(tmp <= ((int)res.size() - i - 1) * 9) {
                res[i] = x + '0';
                cur += x;
                break;
            }
        }
    }
    return res;
}

int sum(string s) {
    int res = 0;
    for(char c : s) {
        if(c < '0' || c > '9') return 0;
        res += c - '0';
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int k;
    cin >> k;

    string res = "19";

    for(int i = 1;i < k;i++) {
        res = next(res);
    }

    cout << res << "\n";

    return 0;
}