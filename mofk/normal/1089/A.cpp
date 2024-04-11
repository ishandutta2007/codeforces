#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second


struct state {
    int g1, g2, s1, s2;
    state (int g1 = 0, int g2 = 0, int s1 = 0, int s2 = 0) {
        this -> g1 = g1;
        this -> g2 = g2;
        this -> s1 = s1;
        this -> s2 = s2;
    }
    state win1(int ns1, int ns2) {
        return state(g1 + 1, g2, s1 + ns1, s2 + ns2);
    }
    state win2(int ns1, int ns2) {
        return state(g1, g2 + 1, s1 + ns1, s2 + ns2);
    }

    bool illegal() {
        if (g1 > 3) return 1;
        if (g2 > 3) return 1;
        if (s1 > 200) return 1;
        if (s2 > 200) return 1;
        return 0;
    }
    bool finish() {
        return g1 == 3 || g2 == 3;
    }
};

int h[5][5][205][205];
pair<state, ii> tr[5][5][205][205];



vector<pair<state, ii>> transfer(state& a) {
    vector<pair<state, ii>> res;
    if (a.finish()) return res;

    int wins = (a.g1 == 2 && a.g2 == 2) ? 15 : 25;
    for(int ns2 = 0; ns2 <= wins - 2; ns2++) {
        res.push_back(make_pair(a.win1(wins, ns2), ii(wins, ns2)));  
    }
    for(int ns1 = 0; ns1 <= wins - 2; ns1++) {
        res.push_back(make_pair(a.win2(ns1, wins), ii(ns1, wins)));  
    }

    for(int ex = wins + 1; ex <= 200; ex++) {
        res.push_back(make_pair(a.win1(ex, ex - 2), ii(ex, ex -2)));
        res.push_back(make_pair(a.win2(ex - 2, ex), ii(ex - 2, ex)));
    }
    return res;
}


bool visit(queue<state> &q, pair<state, ii> move, state& last) {
    state cur = move.X;
    if (!h[cur.g1][cur.g2][cur.s1][cur.s2]) {
        h[cur.g1][cur.g2][cur.s1][cur.s2] = 1;
        tr[cur.g1][cur.g2][cur.s1][cur.s2] = make_pair(last, move.Y);
        q.push(cur);
        return 1;
    }
    return 0;
}
void prepare() {
    queue<state> q;
    q.push(state(0, 0, 0, 0));
    h[0][0][0][0] = 1;



    while (!q.empty()) {
        state cur = q.front(); q.pop();
        //cout << cur.g1 << " " << cur.g2 << " " << cur.s1 << " " << cur.s2 << '\n';
        for(auto move : transfer(cur)) if (!move.X.illegal()){
            visit(q, move, cur);
        }
    }


    //state cur = tr[3][2][80][100].X;
    //cout << cur.g1 << " " << cur.g2 << " " << cur.s1 << " " << cur.s2 << '\n';
    //cout << tr[3][2][80][100].Y.X << " " << 
}

void trace(int f1, int f2, int s1, int s2) {
    vector<ii> res;
    cout << f1 << ":" << f2 << '\n';
    state cur = state(f1, f2, s1, s2);
    while (cur.g1 || cur.g2) {
        res.push_back(tr[cur.g1][cur.g2][cur.s1][cur.s2].Y);
        cur = tr[cur.g1][cur.g2][cur.s1][cur.s2].X;
    }
    reverse(res.begin(), res.end());
    for(auto i : res) cout << i.X << ":" << i.Y << " ";
    cout << '\n';
}
void solve(int s1, int s2) {
    for(int diff = 3; diff > 0; diff--) {
        if (h[3][3 - diff][s1][s2]) {
            trace(3, 3 - diff, s1, s2);
            return;
        }
    }
    for(int diff = 1; diff <= 3; diff++) {
        if (h[3 - diff][3][s1][s2]) {
            trace(3 - diff, 3, s1, s2);
            return;
        }
    }
    cout << "Impossible\n";
}
int main() {
    prepare();
    int test;
    cin >> test;
    while (test--) {
        int s1, s2;
        cin >> s1 >> s2;
        solve(s1, s2);
    }
}