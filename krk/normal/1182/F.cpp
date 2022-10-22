#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxp = 31700;

int t;
int a, b, p, q;
int m1, m2;
map <int, int> M;

int getDist(int a, int b)
{
    return min(abs(a - b), q - abs(a - b));
}

ii getBest(int ind, int took)
{
    int best = q + 1, bi = -1;
    map <int, int>::iterator it = M.lower_bound(ind);
    while (it != M.end() && it->second + took > b)
        M.erase(it++);
    if (it != M.end()) {
        int cand = getDist(it->first, ind);
        int wth = it->second + took;
        if (cand < best || cand == best && wth < bi)
            best = cand, bi = wth;
    }
    while (it != M.begin()) {
        it--;
        if (it->second + took > b)
            M.erase(it++);
        else {
            int cand = getDist(it->first, ind);
            int wth = it->second + took;
            if (cand < best || cand == best && wth < bi)
                best = cand, bi = wth;
            break;
        }
    }
    return ii(best, bi);
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &a, &b, &p, &q);
        m1 = q / 2, m2 = (q + 1) / 2;
        M.clear();
        for (int i = 0; i < Maxp; i++) if (i * Maxp <= b - a) {
            int ind = ll(a + i * Maxp) * p % q;
            map <int, int>::iterator it = M.find(ind);
            if (it == M.end()) M.insert(make_pair(ind, a + i * Maxp));
        }
        int best = q + 1, bi = -1;
        for (int i = 0; i < Maxp; i++) {
            int ind1 = (m1 - ll(i) * p % q + q) % q;
            ii got = getBest(ind1, i);
            if (got.first < best || got.first == best && got.second < bi)
                best = got.first, bi = got.second;
            int ind2 = (m2 - ll(i) * p % q + q) % q;
            got = getBest(ind2, i);
            if (got.first < best || got.first == best && got.second < bi)
                best = got.first, bi = got.second;
        }
        printf("%d\n", bi);
    }
    return 0;
}