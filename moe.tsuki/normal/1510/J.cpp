#include <bits/stdc++.h>
using namespace std;
const int maxn = 500025;

string str;
int N;
void Report(vector<int>);
vector<int> Magic(vector<int> v) {
    // Report(v);
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 1; i--) {
        v[i] -= v[i - 1];
        v[i] -= 1;
    }
    reverse(v.begin(), v.end());
    v.pop_back();
    return v;
}
void Report(vector<int> v) {
    cout << v.size() << '\n';
    for (int x: v)
        cout << x << ' ';
    cout << '\n';
    exit(0);
}
void Case1() {
    if (str[0] == '_' || str[N - 1] == '_')
        return;
    for (int i = 0; i + 1 < N; i++) {
        if (str[i] == '_' && str[i + 1] == '_') {
            return;
        }
    }
    vector<int> ans;
    for (int i = 0, j = 0; i < N; i = j) {
        for (j = i; j < N; j++) {
            if (str[i] != str[j])
                break;
        }
        if (str[i] == '#')
            ans.push_back(j - i);
    }
    Report(ans);
}

int cnt[maxn], minrl;
vector<pair<int,int>> segs;
vector<int> gans;

bool gao(int l, int r, int len) {
    if (len == 2) {
        if ((r - l + 1) % 2 == 0) {
            return false;
        }
    }
    if ((r - l + 1) == 2)
        return false;
    if (l > r)
        return false;
    cerr << "gao " << l << ' ' << r << endl;
    for (int i = l; i <= r; i += 2) {
        if (len == 2 || i + 2 <= r)
            gans.push_back(i);
    }
    if (len > 2)
        gans.push_back(r);
    return true;
}
void Case2() {
    if (str[0] != '_' || str[N - 1] != '_')
        return;
    string S = '?' + str;
    int lasta = -1;
    for (int i = N; i >= 1; i--) {
        if (S[i] == '#') {
            lasta = i;
            break;
        }
    }
    int firsta = -1;
    for (int i = 1; i <= N; i++) {
        if (S[i] == '#') {
            firsta = i;
            break;
        }
    }
    assert (firsta != -1);
    ++lasta;
    --firsta;
    for (int fk = N; fk >= 0; fk--) {
        int len = N + 2 - fk;
        gans.clear();
        if (!gao(0, fk - lasta, len) ||
                !gao(N - firsta + 1, fk, len))
            continue;
        if (len > minrl)
            continue;
        if (cnt[len + 1] != 0)
            continue;
        bool fail = false;
        for (auto [l, r]: segs) {
            int fl, fr;
            fr = fk - l;
            fl = N - r + 1;
            if (len == 2) {
                if (!gao(fl, fr, len)) {
                    fail = true;
                    break;
                }
            } else {
                assert (gao(fl, fr, len));
            }
        }
        if (fail)
            continue;
        Report(Magic(gans));
    }
}

void Case0() {
    for (int i = 0; i < N; i++)
        if (str[i] != '_')
            return;
    Report({});
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> str;
    N = str.size();
    {
        minrl = 1e9;
        for (int i = 0, j; i < N; i = j) {
            for (j = i; j < N; j++) {
                if (str[i] != str[j])
                    break;
            }
            if (str[i] == '_') {
                if (i != 0 && j != N) {
                    cnt[j - i] += 1;
                    minrl = min(minrl, j - i);
                    segs.emplace_back(i + 1, j);
                }
            }
        }
    }
    Case0();
    Case1();
    Case2();
    cout << -1 << '\n';
    return 0;
}

/*
   __#_____#___
3
2 3 2

Press ENTER or type command to continue
__#__#__
-1

Press ENTER or type command to continue
_#__#_
j: j.cpp:94: void Case2(): Assertion `gao(l, r, len)' failed.


*/