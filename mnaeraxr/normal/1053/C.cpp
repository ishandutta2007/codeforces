#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int add(int a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b){
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

struct segment_tree{
    vector<int64> w;
    vector<int> x, y;

    segment_tree(vi &A, vi &W){
        int n = (int)A.size();
        w = vector<int64>(4 * n);
        x = vi(4 * n);
        y = vi(4 * n);

        build(1, 0, n, A, W);
    }

    void build(int p, int b, int e, vi &A, vi &W){
        if (b + 1 == e){
            w[p] = W[b];

            x[p] = sub(b, A[b]);
            x[p] = 1LL * x[p] * w[p] % mod;

            y[p] = sub(A[b], b);
            y[p] = 1LL * y[p] * w[p] % mod;
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            build(l, b, m, A, W);
            build(r, m, e, A, W);

            w[p] = w[l] + w[r];
            x[p] = add(x[l], x[r]);
            y[p] = add(y[l], y[r]);
        }
    }

    void update(int p, int b, int e, int z, int v, vector<int> &A){
        if (b + 1 == e){
            w[p] = v;

            x[p] = sub(b, A[b]);
            x[p] = 1LL * x[p] * w[p] % mod;

            y[p] = sub(A[b], b);
            y[p] = 1LL * y[p] * w[p] % mod;
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            if (z < m) update(l, b, m, z, v, A);
            if (m <= z) update(r, m, e, z, v, A);

            w[p] = w[l] + w[r];
            x[p] = add(x[l], x[r]);
            y[p] = add(y[l], y[r]);
        }
    }

    int64 sum(int p, int b, int e, int L, int R){
        if (L <= b && e <= R)
            return w[p];
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            int64 answer = 0;

            if (L < m) answer += sum(l, b, m, L, R);
            if (m < R) answer += sum(r, m, e, L, R);

            return answer;
        }
    }

    int find(int p, int b, int e, int64 P){
        if (b + 1 == e){
            return 2 * w[p] <= P ? e : b;
        }

        int m = (b + e) >> 1, l = p << 1, r = l | 1;

        if (2 * w[l] <= P)
            return find(r, m, e, P - 2 * w[l]);
        else
            return find(l, b, m, P);
    }

    int solve_le(int p, int b, int e, int L, int R){
        if (L == R) return 0;

        if(L <= b && e <= R)
            return x[p];
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            int answer = 0;

            if (L < m) answer = add(answer, solve_le(l, b, m, L, R));
            if (m < R) answer = add(answer, solve_le(r, m, e, L, R));

            return answer;
        }
    }

    int solve_ri(int p, int b, int e, int L, int R){
        if (L == R) return 0;

        if(L <= b && e <= R){
            return y[p];
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            int answer = 0;

            if (L < m) answer = add(answer, solve_ri(l, b, m, L, R));
            if (m < R) answer = add(answer, solve_ri(r, m, e, L, R));

            return answer;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    vector<int> A(n + 1), W(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    for (int i = 1; i <= n; ++i)
        cin >> W[i];

    int N = n + 1;

    segment_tree st(A, W);

    while (q-->0){
        int x, y;
        cin >> x >> y;

        if (x < 0){
            st.update(1, 0, N, -x, y, A);
        }
        else{
            int l = x, r = y;

            int64 PR = st.sum(1, 0, N, 0, r + 1);
            int64 PL = st.sum(1, 0, N, 0, l);

            int k = st.find(1, 0, N, PR + PL);

            int c = A[k] - (k - l);

            int lll = st.solve_le(1, 0, N, l, k);
            int rrr = st.solve_ri(1, 0, N, k, r + 1);

            int answer = add(lll, rrr);

            int ll = st.sum(1, 0, N, l, k) % mod;
            int rr = st.sum(1, 0, N, k, r + 1) % mod;

            answer = add(answer, 1LL * ll * sub(c, l) % mod);
            answer = add(answer, 1LL * rr * sub(l, c) % mod);

            cout << answer << endl;
        }
    }

    return 0;
}