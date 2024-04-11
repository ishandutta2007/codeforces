#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 3;
const ll Inf = 4000000000000000000ll;

struct pt{
    long long x, y;
    pt operator + (const pt & p) const {
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p) const {
        return pt{x - p.x, y - p.y};
    }
    long long cross(const pt & p) const {
        return x * p.y - y * p.x;
    }
    bool operator <(const pt &oth) const {
        if (x != oth.x) return x < oth.x;
        return y < oth.y;
    }
};

vector <pt> seq[Maxd];
ll mn = Inf, mx = -Inf;
map <pt, pt> Mlow, Mupp;

void reorder_polygon(vector<pt> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<pt> minkowski(vector<pt> P, vector<pt> Q){
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<pt> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
        if(cross >= 0)
            ++i;
        if(cross <= 0)
            ++j;
    }
    return result;
}

void Read(vector <pt> &seq)
{
    int n; scanf("%d", &n);
    seq.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d %I64d", &seq[i].x, &seq[i].y);
}

int main()
{
    for (int i = 0; i < Maxd; i++)
        Read(seq[i]);
    auto tmp = minkowski(minkowski(seq[0], seq[1]), seq[2]);
    for (int i = 0; i < tmp.size(); i++) {
        int ni = (i + 1) % int(tmp.size());
        mn = min(mn, tmp[i].x);
        mx = max(mx, tmp[i].x);
        if (tmp[i].x < tmp[ni].x)
            Mlow[{tmp[i].x, tmp[i].y}] = {tmp[ni].x - tmp[i].x, tmp[ni].y - tmp[i].y};
        else if (tmp[i].x > tmp[ni].x)
            Mupp[{tmp[ni].x, tmp[ni].y}] = {tmp[i].x - tmp[ni].x, tmp[i].y - tmp[ni].y};
    }
    int m; scanf("%d", &m);
    while (m--) {
        ll x, y; scanf("%I64d %I64d", &x, &y);
        x *= 3ll; y *= 3ll;
        if (x < mn || x > mx) { printf("NO\n"); continue; }
        auto it = Mupp.lower_bound({x + 1, -Inf});
        it--;
        pt my = {x - it->first.x, y - it->first.y};
        if (my.cross(it->second) < 0) { printf("NO\n"); continue; }
        it = Mlow.lower_bound({x + 1, -Inf});
        it--;
        my = {x - it->first.x, y - it->first.y};
        if (my.cross(it->second) > 0) { printf("NO\n"); continue; }
        printf("YES\n");
    }
    return 0;
}