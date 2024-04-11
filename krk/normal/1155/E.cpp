#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000003;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

vector <int> Multiply(const vector <int> &A, const vector <int> &B)
{
    vector <int> C(int(A.size()) + int(B.size()) - 1, 0);
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] = (C[i + j] + ll(A[i]) * B[j]) % mod;
    return C;
}

vector <int> Add(const vector <int> &A, const vector <int> &B)
{
    vector <int> C(A.size(), 0);
    for (int i = 0; i < A.size(); i++)
        C[i] = (A[i] + B[i]) % mod;
    return C;
}

vector <int> Mult(vector <int> V, int mult)
{
    for (int i = 0; i < V.size(); i++)
        V[i] = ll(V[i]) * mult % mod;
    return V;
}

int Ask(int x)
{
    printf("? %d\n", x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Answer(int x)
{
    printf("! %d\n", x); fflush(stdout);
}

const int Maxn = 11;
int Y[Maxn];

int Eval(const vector <int> &P, int x)
{
    int y = 0;
    for (int i = int(P.size()) - 1; i >= 0; i--) {
        y = ll(y) * x % mod;
        y = (y + P[i]) % mod;
    }
    return y;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        int g = Ask(i);
        if (g == 0) { Answer(i); return 0; }
        Y[i] = g;
    }
    vector <int> P(Maxn, 0);
    for (int i = 0; i < Maxn; i++) {
        vector <int> cur(1, 1);
        for (int j = 0; j < Maxn; j++) if (i != j) {
            int mult = Inv((i - j + mod) % mod);
            vector <int> add(2);
            add[0] = (mod - j) % mod;
            add[1] = 1;
            add[0] = ll(add[0]) * mult % mod;
            add[1] = ll(add[1]) * mult % mod;
            cur = Multiply(cur, add);
        }
        assert(cur.size() == 11);
        P = Add(P, Mult(cur, Y[i]));
    }
    for (int i = Maxn; i < mod; i++)
        if (Eval(P, i) == 0) { Answer(i); return 0; }
    Answer(-1);
    return 0;
}