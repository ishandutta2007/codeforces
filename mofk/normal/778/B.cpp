#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

struct var {
    string value;
    int ptr[2]; int type;
};

int conv(string s) {
    if (s == "AND") return 0;
    if (s == "OR") return 1;
    if (s == "XOR") return 2;
    return -1;
}

int N, M;
map <string, int> id;
var a[5005];
bool v[5005];

int calc(int pos, bool b) {
    int ret = 0;
    v[1] = b;
    ff(i, 2, N + 1) {
        if (a[i].value.empty()) {
            if (a[i].type == 0) v[i] = v[a[i].ptr[0]] & v[a[i].ptr[1]];
            if (a[i].type == 1) v[i] = v[a[i].ptr[0]] | v[a[i].ptr[1]];
            if (a[i].type == 2) v[i] = v[a[i].ptr[0]] ^ v[a[i].ptr[1]];
        }
        else v[i] = (a[i].value[pos] == '1');
    }
    ff(i, 2, N + 1) ret += v[i];
    //cout << pos << " " << b << " " << ret << endl;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    string s, tmp, type;
    id["?"] = 1;
    ff(i, 2, N + 1) {
        cin >> s;
        id[s] = i;
        cin >> tmp >> tmp;
        if (tmp[0] == '0' || tmp[0] == '1') a[i].value = tmp;
        else {
            a[i].ptr[0] = id[tmp];
            cin >> type >> tmp;
            a[i].type = conv(type);
            a[i].ptr[1] = id[tmp];
        }
    }
    string ans;
    ff(i, 0, M - 1) if (calc(i, 0) > calc(i, 1)) ans += '1'; else ans += '0';
    cout << ans << endl; ans.clear();
    ff(i, 0, M - 1) if (calc(i, 0) < calc(i, 1)) ans += '1'; else ans += '0';
    cout << ans << endl;
    return 0;
}