#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10 ;

struct point {
    int x, speed;
    point () : x(), speed () {}
    point (int x, int speed) : x(x) , speed (speed) {}
    bool operator < (const point & a) const {
        return speed == a.speed ? x < a.x : speed < a.speed;;
    }

};
int n;
bool cmp (const point &a, const point & b){
    return a.x < b.x;
}
point p[nax];
long long s ;
vector<int> c;
template<typename T>
struct fenwick {
    T bit[nax];
    void update (int idx, T val) {
        for (; idx <= n ; idx += idx & -idx)
            bit[idx] += val;
    }
    T get (int idx) {
        T res = 0;
        for (; idx > 0 ; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
    T get (int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};
fenwick<int> f1;
fenwick<long long> f2;


int main () {
    scanf("%d", &n);
    c.emplace_back(numeric_limits<int>::min());
    for (int i = 1 ;i <= n ; ++ i) {
        scanf("%d", &p[i].x);
        c.emplace_back(p[i].x);
    }
    sort(c.begin(), c.end());
    auto where = [&] (int v) -> int{
        return (int) (lower_bound(c.begin(), c.end(), v) - c.begin());
    };

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", &p[i].speed);
    }
    sort(p + 1 , p + 1 + n, cmp);
    for (int i = 1 ; i < n ; ++ i) {
        int dist = p[i + 1].x - p[i].x;
        s += 1LL * dist * (i) * (n - i);
    }
    sort(p + 1 , p + 1 + n);
    for (int i = 1 ; i <= n ; ++ i) {
        int x = p[i].x ;
        int now = where(x);
        int many = f1.get(now + 1, n);
        long long sum = f2.get(now + 1 , n);
        s -= sum;
        s += 1LL * x * many ;
        f1.update(now , 1);
        f2.update(now, x);
    }
    printf("%lld\n", s );
}