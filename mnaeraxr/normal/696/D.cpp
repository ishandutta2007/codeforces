#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct matrix{
    int n;
    int64 m[210][210];

    matrix(int n) : n(n){
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[i][j] = -oo;
    }

    matrix operator *(const matrix &M) const{
        matrix a(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if (m[i][k] >= 0 && M.m[k][j] >= 0)
                        a.m[i][j] = max(a.m[i][j], m[i][k] + M.m[k][j]);

        return a;
    }

    void print() const{
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << (m[i][j] < 0 ? -1 : m[i][j]) << " \n"[j + 1 == n];
        cout << endl;
    }
};

matrix identity(int n)
{
    matrix I(n);

    for (int i = 0; i < n; ++i)
        I.m[i][i] = 0;

    return I;
}

matrix fpow(matrix m, int64 n)
{
    matrix a = identity(m.n);

    for (int i = 0; i < 63; ++i){
        if (n >> i & 1) a = a * m;
        m = m * m;
    }

    return a;
}

const int alpha = 26;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int64 l;
    cin >> l;

    vector<int64> a(n);
    for (int64 &x : a)
        cin >> x;

    vector<vector<int>> go(2, vector<int>(alpha));
    vector<int> fail(2);
    vector<int64> cost(2, 0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        int st = 1;

        for (char c : s)
        {
            if (!go[st][c - 'a'])
            {
                go[st][c - 'a'] = go.size();
                go.emplace_back(vector<int>(alpha));
                cost.push_back(0);
                fail.push_back(0);
            }

            st = go[st][c - 'a'];
        }

        cost[st] += a[i];
    }

    queue<int> q;

    for (int c = 0; c < alpha; ++c)
        if (!go[1][c]) go[1][c] = 1;
        else fail[go[1][c]] = 1, q.push(go[1][c]);

    for (; !q.empty(); q.pop())
    {
        int st = q.front(), f = fail[st];

        for (int c = 0; c < 26; ++c)
            if (!go[st][c]) go[st][c] = go[f][c];
            else
            {
                q.push(go[st][c]);
                fail[go[st][c]] = go[f][c];
                cost[go[st][c]] += cost[go[f][c]];
            }
    }

    matrix A(go.size());

    for (int st = 1; st < go.size(); ++st)
        for (int c = 0; c < alpha; ++c)
            A.m[st][go[st][c]] = cost[go[st][c]];

    A = fpow(A, l);

    int64 best = -oo;

    for (int i = 0; i < go.size(); ++i)
        best = max(best, A.m[1][i]);

    cout << best << endl;

    return 0;
}