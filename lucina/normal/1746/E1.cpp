#include<bits/stdc++.h>
using namespace std;

int ask(vector <int> f) {
    //assert(!f.empty());
    cout << "? ";
    cout << f.size() << ' ';
    for (int j : f) cout << j << ' ';
    cout << endl;
    string x;
    cin >> x;
    return (x == "YES");
}

void try_ans(int x) {
    cout << "! " << x << endl;
    string res;
    cin >> res;
    if (res == ":)") exit(0);
}

vector <int> operator +(vector <int> a, const vector <int> &b) {
    for (int j : b) a.push_back(j);
    return a;
}

vector <set <int>> prepare() {
    vector <int> t = {1 + 2, 4 + 8, 1 + 4, 2 + 8};
    vector <int> tamper;
    for (int i = 0 ; i < 16 ; ++ i) {
        for (int j = 0 ; j < 3 ; ++ j) {
            if (((i >> j & 1) + (i >> (j + 1) & 1)) >= 2) goto FF;
        }
        tamper.push_back(i);
        FF:;
    }
    vector <set <int>> prep;
    for (auto x : t) {
        set <int> g;
        for (auto k : tamper) {
            g.insert(x ^ k);
        }
        prep.push_back(g);
    }
    return prep;
}

int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector <set <int>> prep = prepare();
    vector <int> cur[2];
    for (int i = 1 ; i <= n ; ++ i) {
        cur[i % 2].push_back(i);
    }
    vector <int> f[4];
    while (cur[0].size() + cur[1].size() > 2) {
        for (int i = 0 ; i < 4 ; ++ i) f[i].clear();
        for (int i = 0 ; i < 2 ; ++ i) {
            for (int j = 0 ; j < cur[i].size() ; ++ j) {
                f[i * 2 + j % 2].push_back(cur[i][j]);
            }
        }
        int c = 0, cnt = 0;
        for (int x = 0 ; x < 2 ; ++ x) {
            for (int y = 2 ; y < 4 ; ++ y) {
                c += ask(f[x] + f[y]) << cnt;
                cnt += 1;
            }
        }

        for (int i = 0, qq = 0 ; i < 4 ; ++ i) if (prep[i].count(c)) {
            cur[qq ++].swap(f[i]);
        }
    }

    for (int j : cur[0])
        try_ans(j);
    for (int j : cur[1])
        try_ans(j);
}
/**
    Global round, GL

*/


    /**
        just mapping

        1 0 0 0
        0 1 0 0
        0 0 1 0
        0 0 0 1

        map first two and last two

        -> 1 1 0 0, 0 0 1 1, 1 0 1 0, 0 1 0 1

        For some reasons, which I don't care much,
        tampering vector map these sets into half set,
        And one number belong to exactly two sets,

        So we can keep track of all possible twos, and go on
        use only 64 + 2 queries

        Let's care for reasons a bit,
        if these twos are going to have equal XOR
        XOR -> this,1111, 0110, 1001, 1001, 0110, 1111
        For any 4-bit number, XOR 1100 0011 1010 0101,
        two will result in valid tampering, another two will result in invalid tampering
    */