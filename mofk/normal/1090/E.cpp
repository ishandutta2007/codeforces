#include <bits/stdc++.h>

using namespace std;

int id(int r, int c) {
    if (r < 1 || r > 8 || c < 1 || c > 8) return -1;
    return (r - 1) * 8 + c;
}
int id(string s) {
    int c = s[0] - 'a' + 1;
    int r = s[1] - '0';
    return id(r, c);
}
string str(int x) {
    string s = "a1";
    s[0] = 'a' + (x - 1) % 8;
    s[1] = '1' + (x - 1) / 8;
    return s;
}
string move(int x, int y) {
    return str(x) + "-" + str(y);
}

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector<int> adj[100];

vector<string> prints;
int k;
int board[100];

vector<int> find_path(int fr, int to) {
    queue<int> q;
    vector<int> tr(100, 0);
    q.push(fr);
    tr[fr] = fr;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (tr[v]) continue;
            tr[v] = u;
            q.push(v);
        }
    }
    vector<int> ret;
    ret.push_back(to);
    while (to != fr) {
        to = tr[to];
        ret.push_back(to);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            int u = id(i, j);
            for (int z = 0; z < 8; ++z) {
                int ni = i + dx[z], nj = j + dy[z];
                int v = id(ni, nj);
                if (v != -1) adj[u].push_back(v);
            }
        }
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        int u = id(s);
        board[u] = 1;
    }

    for (int i = 1; i <= k; ++i) {
        if (board[i]) continue;
        int u = i;
        while (!board[u]) ++u;
        vector<int> path = find_path(u, i);
        int ptr = 0;
        while (path[ptr] != i) {
            vector<string> buf;
            buf.push_back(move(path[ptr], path[ptr + 1]));
            ++ptr;
            while (board[path[ptr]]) {
                buf.push_back(move(path[ptr], path[ptr + 1]));
                ++ptr;
            }
            while (buf.size()) {
                prints.push_back(buf.back());
                buf.pop_back();
            }
        }

        board[i] = 1;
        board[u] = 0;
    }

    cout << prints.size() << endl;
    for (auto s: prints) cout << s << endl;
    return 0;
}