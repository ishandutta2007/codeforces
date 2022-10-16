#include <iostream>
#include <set>

using namespace std;

multiset<int> h, hl, v, vl;

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0);
    int W, H, q, r, c, nr, nc, pr, pc;
    auto tmp = h.begin();
    char t;
    cin >> W >> H >> q;
    int64_t mv = H, mh = W;
    h.insert(0);
    h.insert(W);
    hl.insert(W);
    v.insert(0);
    v.insert(H);
    vl.insert(H);
    while (q--)
    {
        cin >> t;
        if (t == 'H')
        {
            cin >> r;
            pr = *prev(tmp = v.upper_bound(r));
            nr = *tmp;
            v.insert(r);
            vl.erase(vl.find(nr - pr));
            vl.insert(r - pr);
            vl.insert(nr - r);
            mv = *(prev(vl.end()));
        }
        else
        {
            cin >> c;
            pc = *prev(tmp = h.upper_bound(c));
            nc = *(tmp);
            h.insert(c);
            hl.erase(hl.find(nc - pc));
            hl.insert(c - pc);
            hl.insert(nc - c);
            mh = *prev(hl.end());
        }
        cout << mv * mh << '\n';
    }
    return 0;
}