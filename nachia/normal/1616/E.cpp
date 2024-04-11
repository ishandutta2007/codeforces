
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


struct segtree_min {
    struct S { char a; };
    static S op(S l, S r) { return { min(l.a, r.a) }; }
    static S e() { return { 'z'+1 }; }

    int N;
    vector<S> A;

    void mergev(int i) {
        if (i < N) A[i] = op(A[i * 2], A[i * 2 + 1]);
    }

    segtree_min(int n) {
        N = 1; while (N < n) N *= 2;
        A.assign(N * 2, e());
    }
    segtree_min(const string& a) : segtree_min(a.size()) {
        for (int i = 0; i < a.size(); i++) A[i + N] = {a[i]};
        for (int i = N - 1; i >= 1; i--) mergev(i);
    }

    void set(int p, S x) {
        p += N; A[p] = x;
        for (int d = 1; (1 << d) <= N; d++) mergev(p >> d);
    }

    S prod(int l, int r, int a = 0, int b = 0, int i = -1) {
        if (i == -1) { a = 0; b = N; i = 1; }
        if (r <= a || b <= l) return e();
        if (l <= a && b <= r) return A[i];
        S q1 = prod(l, r, a, (a + b) / 2, i * 2);
        S q2 = prod(l, r, (a + b) / 2, b, i * 2 + 1);
        return op(q1, q2);
    }

    // bool cmp(S)
    template<class E>
    int minleft(int r, E cmp, int a = 0, int b = 0, int i = -1) {
        static S x;
        if (i == -1) { a = 0; b = N; i = 1; x = e(); }
        if (r <= a) return a;
        if (b <= r) {
            S nx = op(A[i], x);
            if (cmp(nx)) { x = nx; return a; }
        }
        if (b - a == 1) return b;
        int q = minleft(r, cmp, (a + b) / 2, b, i * 2 + 1);
        if (q > (a + b) / 2) return q;
        return minleft(r, cmp, a, (a + b) / 2, i * 2);
    }

    // bool cmp(S)
    template<class E>
    int maxright(int l, E cmp, int a = 0, int b = 0, int i = -1) {
        static S x;
        if (i == -1) { a = 0; b = N; i = 1; x = e(); }
        if (b <= l) return b;
        if (l <= a) {
            S nx = op(x, A[i]);
            if (cmp(nx)) { x = nx; return b; }
        }
        if (b - a == 1) return a;
        int q = maxright(l, cmp, a, (a + b) / 2, i * 2);
        if (q < (a + b) / 2) return q;
        return maxright(l, cmp, (a + b) / 2, b, i * 2 + 1);
    }
};


struct segtree_add {
    struct S { int a; };
    static S op(S l, S r) { return { l.a + r.a }; }
    static S e() { return { 0 }; }

    int N;
    vector<S> A;

    void mergev(int i) {
        if (i < N) A[i] = op(A[i * 2], A[i * 2 + 1]);
    }

    segtree_add(int n) {
        N = 1; while (N < n) N *= 2;
        A.assign(N * 2, e());
    }
    segtree_add(const vector<S>& a) : segtree_add(a.size()) {
        for (int i = 0; i < a.size(); i++) A[i + N] = a[i];
        for (int i = N - 1; i >= 1; i--) mergev(i);
    }

    void set(int p, S x) {
        p += N; A[p] = x;
        for (int d = 1; (1 << d) <= N; d++) mergev(p >> d);
    }

    S prod(int l, int r, int a = 0, int b = 0, int i = -1) {
        if (i == -1) { a = 0; b = N; i = 1; }
        if (r <= a || b <= l) return e();
        if (l <= a && b <= r) return A[i];
        S q1 = prod(l, r, a, (a + b) / 2, i * 2);
        S q2 = prod(l, r, (a + b) / 2, b, i * 2 + 1);
        return op(q1, q2);
    }

    // bool cmp(S)
    template<class E>
    int minleft(int r, E cmp, int a = 0, int b = 0, int i = -1) {
        static S x;
        if (i == -1) { a = 0; b = N; i = 1; x = e(); }
        if (r <= a) return a;
        if (b <= r) {
            S nx = op(A[i], x);
            if (cmp(nx)) { x = nx; return a; }
        }
        if (b - a == 1) return b;
        int q = minleft(r, cmp, (a + b) / 2, b, i * 2 + 1);
        if (q > (a + b) / 2) return q;
        return minleft(r, cmp, a, (a + b) / 2, i * 2);
    }

    // bool cmp(S)
    template<class E>
    int maxright(int l, E cmp, int a = 0, int b = 0, int i = -1) {
        static S x;
        if (i == -1) { a = 0; b = N; i = 1; x = e(); }
        if (b <= l) return b;
        if (l <= a) {
            S nx = op(x, A[i]);
            if (cmp(nx)) { x = nx; return b; }
        }
        if (b - a == 1) return a;
        int q = maxright(l, cmp, a, (a + b) / 2, i * 2);
        if (q < (a + b) / 2) return q;
        return maxright(l, cmp, (a + b) / 2, b, i * 2 + 1);
    }
};




void testcase(){
    int N; cin >> N;
    string S,T; cin >> S >> T;

    segtree_min rmq(S);
    segtree_add rsq(vector<segtree_add::S>(N, {1}));

    i64 ans = 1001001001001001001;
    i64 pans = 0;
    for(char c : T){
        // strictly smaller
        int strictp = rmq.maxright(0, [c](segtree_min::S x)->bool{ return c <= x.a; });
        int equalp = rmq.maxright(0, [c](segtree_min::S x)->bool{ return c < x.a; });
        if(strictp < N){
            i64 tmp = pans + rsq.prod(0, strictp).a;
            ans = min(ans, tmp);
        }
        if(equalp == strictp) break;

        // equal
        if(equalp >= N){ cout << "-1\n"; return; }
        if(equalp < N){
            pans = pans + rsq.prod(0, equalp).a;
            rsq.set(equalp, {0});
            rmq.set(equalp, {(char)('z'+1)});
        }
    }

    if(ans < 1001001001001001001) cout << ans << "\n";
    else cout << "-1\n";
}


int main(){
    int T; cin >> T;
    rep(caseid, T) testcase();
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;