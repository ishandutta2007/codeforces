#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
struct {
    
    long long b[N << 2], laz[N << 2];
    void build(int node, int L, int R){
        if (L == R) {
            b[node] = L;
            return;
        }
        build(node * 2, L, (L + R) / 2);
        build(node * 2 + 1, (L + R) / 2 + 1, R);
        b[node] = max(b[node * 2], b[node * 2 + 1]);
    }
    void lazyupdate(int node, int L, int R) {
        b[node] += laz[node];
        if (L < R) {
            laz[node * 2] += laz[node];
            laz[node * 2 + 1] += laz[node];
        }
        laz[node] = 0;
    }

    void update(int node, int L, int R, int l, int r, int val) {
        lazyupdate(node, L, R);
        if (L > r || R < l) return;
        if (l <= L && R <= r) {
            laz[node] += val;
            lazyupdate(node, L, R);
            return;
        }
        update(node * 2, L, (L + R) / 2, l, r, val);
        update(node * 2 + 1, (L + R) / 2 + 1, R, l, r, val);
        b[node] = max(b[node * 2], b[node * 2 + 1]);
    }
    long long get(int node, int L, int R, int l, int r) {
        lazyupdate(node, L, R);
        if (L > r || R < l) return 0;
        if (l <= L && R <= r) return b[node];
        return max(get(node * 2, L, (L + R) / 2, l, r),
            get(node * 2 + 1, (L + R) / 2 + 1, R, l, r));
    }
}mseg;

struct {
    long long b[N];
    void add(int x, int val) {
        while (x) {
            b[x] += val;
            x -= x &-x;
        }
    }
    long long get(int x) {
        long long ans = 0;
        while (x < N) {
            ans += b[x];
            x += x & -x;
        }
        return ans;
    }
}mbit;


int qu[N][2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    
    mseg.build(1, 1, 1000000);
    for(int i = 1; i <= test; i++) {
        char ch;
        cin >> ch;
        if (ch == '+') {
            cin >> qu[i][0] >> qu[i][1];
            mseg.update(1, 1, 1000000, 1, qu[i][0], qu[i][1]);
            mbit.add(qu[i][0], qu[i][1]);
            continue;
        }
        if (ch == '-') {
            int pos;
            cin >> pos;
            mseg.update(1, 1, 1000000, 1, qu[pos][0], -qu[pos][1]);
            mbit.add(qu[pos][0], -qu[pos][1]);
        }
        if (ch == '?') {
            int pos;
            cin >> pos;
            cout << mseg.get(1, 1, 1000000, 1, pos) - mbit.get(pos + 1) - pos << '\n'; 
        }
    }
}