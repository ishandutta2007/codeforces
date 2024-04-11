
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll k;
string s;
int sz[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    fill(sz, sz + n, -1);
    bool special = true;
    int r = -1;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if(s[i] != s[j]) r = j;
        else special = false;
    }
    if(special && k % 2 == 1) {
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    if(r == -1 || special) {
        cout << s << endl;
        return 0;
    }
    int rot = 0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int j2 = (i + 2) % n;
        if(s[i] != s[j] && s[j] == s[j2]) {
            rot = j;
            rotate(s.begin(), s.begin() + j, s.end());
            break;
        }
    }
    int f = 1;
    vector<int> v;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            f++;
        }else {
            v.push_back(f);
            f = 1;
        }
    }
    v.push_back(f);
    v.push_back(2);

    vector<int> v2;
    int i = 0;
    while(i + 1 < v.size()) {
        int j = i + 1;
        while(v[j] == 1) j++;
        ll ones = j - i - 1;
        ll rem = min(2 * k, ones);
        if(rem == ones && ones % 2 == 0) {
            v2.push_back(v[i] + ones / 2);
            v[j] += ones / 2;
        }else if(rem < ones) {
            v2.push_back(v[i] + k);
            for(int l = 0; l < ones - rem; l++) {
                v2.push_back(1);
            }
            v[j] += k;
        }else {
            v[j] += v[i] + ones;
        }
        i = j;
    }
    v2.push_back(v.back());

    char c[2] = {s[0], (s[0] == 'B' ? 'W' : 'B')};
    s = "";
    for(i = 0; i < v2.size(); i++) {
        for(int j = 0; j < v2[i] && s.length() < n; j++) {
            s.push_back(c[i % 2]);
        }
    }
    rotate(s.begin(), s.begin() + n - rot, s.end());
    cout << s << endl;
}