#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int go[maxn][26], fail[maxn];
int I[maxn], F[maxn], S[maxn], FIN[maxn];
int total;

void push(string &s, int index, int freq){
    int u = 0;

    for (auto c : s){
        int x = c - 'a';
        if (!go[u][x])
            go[u][x] = total++;
        u = go[u][x];
    }

    I[u] = index, F[u] = freq, S[u] = s.length(), FIN[u] = u;
}

void build(){
    queue<pii> q;

    for (int i = 0; i < 26; ++i){
        if (go[0][i])
            q.push({go[0][i], 0});
    }

    while (!q.empty()){
        auto x = q.front(); q.pop();
        int u = x.first, f = x.second;

        fail[u] = f;

        if (!FIN[u])
            FIN[u] = FIN[f];

        for (int i = 0; i < 26; ++i){
            if (go[u][i])
                q.push({go[u][i], go[f][i]});
            else
                go[u][i] = go[f][i];
        }
    }
}

int ANSWER[maxn];
queue<int> deq[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    total = 1;

    string s; cin >> s;

    int q; cin >> q;

    for (int i = 1; i <= q; ++i){
        int f;
        string t;
        cin >> f >> t;
        push(t, i, f);
    }

    build();

    memset(ANSWER, 0x3f, sizeof ANSWER);

    for (int i = 0, u = 0; i < (int)s.length(); ++i){
        u = go[u][s[i] - 'a'];

        int v = FIN[u];

        while (v){
            int idx = I[v];
            deq[idx].push(i);

            if (deq[idx].size() > F[v])
                deq[idx].pop();

            if (deq[idx].size() == F[v]){
                int beg = deq[idx].front();
                // cout << v << " " << i << " " << beg << " " << S[v] << endl;
                ANSWER[idx] = min(ANSWER[idx], i - beg + S[v]);
            }

            v = FIN[fail[v]];
        }
    }

    for (int i = 1; i <= q; ++i){
        if (ANSWER[i] == oo)
            cout << -1 << endl;
        else
            cout << ANSWER[i] << endl;
    }

    return 0;
}