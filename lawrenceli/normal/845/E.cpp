#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxk = 505;
const int inf = 1e9;

int n, m, k;
int px[maxk], py[maxk];

int minx, maxx, miny, maxy;
pair<pair<int, int>, pair<int, int> > vs[2 * maxk]; int sze;
multiset<pair<int, int> > st;

void updx(int x) {
    minx = min(minx, x);
    maxx = max(maxx, x);
}

void updy(int y) {
    miny = min(miny, y);
    maxy = max(maxy, y);
}

void updv(int lx, int rx) {
    if (st.empty()) {
        updx(lx), updx(rx), updy(0), updy(m - 1);
        return;
    }

    if (st.begin()->A > 0) {
        updx(lx), updx(rx), updy(0), updy(st.begin()->A - 1);
    }

    int num = 0;
    for (auto it = st.begin(), jt = st.begin(); it != st.end(); it = jt) {
        for (jt = it; jt != st.end() && jt->A == it->A; jt++) {
            if (jt->B) num--;
            else num++;
        }

        assert(num >= 0);
        if (num == 0) {
            int ly = it->A;
            int ry = (jt == st.end() ? m : jt->A) - 1;
            if (ly <= ry) {
                updx(lx), updx(rx), updy(ly), updy(ry);
            }
        }
    }
}

bool check(int t) {
    minx = miny = inf;
    maxx = maxy = -inf;
    sze = 0;
    st.clear();
    for (int i = 0; i < k; i++) {
        int lx = max(0, px[i] - t);
        int rx = min(n, px[i] + t + 1);
        int ly = max(0, py[i] - t);
        int ry = min(m, py[i] + t + 1);
        vs[sze++] = MP(MP(lx, 0), MP(ly, ry));
        vs[sze++] = MP(MP(rx, 1), MP(ly, ry));
    }

    sort(vs, vs + sze);
    if (vs[0].A.A > 0) {
        updx(0), updx(vs[0].A.A - 1), updy(0), updy(m - 1);
    }

    for (int i = 0, j; i < 2 * k; i = j) {
        for (j = i; j < 2 * k && vs[j].A.A == vs[i].A.A; j++) {
            pair<int, int> p1 = MP(vs[j].B.A, 0);
            pair<int, int> p2 = MP(vs[j].B.B, 1);
            if (vs[j].A.B == 0) {
                st.insert(p1), st.insert(p2);
            } else {
                st.erase(st.find(p1));
                st.erase(st.find(p2));
            }
        }

        int lx = vs[i].A.A;
        int rx = (j == 2 * k ? n : vs[j].A.A) - 1;
        if (lx <= rx) updv(lx, rx);
    }

    //no empty blocks
    if (minx > maxx) {
        assert(miny > maxy);
        return true;
    }

    int need = max(maxx - minx + 1, maxy - miny + 1) / 2;
    return t >= need;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> px[i] >> py[i];
        px[i]--, py[i]--;
    }

    int lo = 0, hi = inf;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}