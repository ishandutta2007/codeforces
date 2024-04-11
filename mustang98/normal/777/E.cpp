#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_f = 200222;

struct circle {
    int rl, rb, h;
};

circle c[max_n];

bool comp(const circle &c1, const circle &c2)
{
    if (c1.rb == c2.rb) return c1.rl > c2.rl;
    return c1.rb > c2.rb;
}

vector<int> rad;
map<int, int> newrad;

ll fen[max_f] = {0};

ll get_max(int ind)
{
    ll maxx = 0;
    for (int i = ind; i >= 0; i = (i & (i + 1)) - 1)
    {
        maxx = max(maxx, fen[i]);
    }
    return maxx;
}

void upd(int ind, ll val)
{
    for (int i = ind; i < max_f; i |= (i + 1))
    {
        fen[i] = max(fen[i], val);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &c[i].rl, &c[i].rb, &c[i].h);
        rad.pb(c[i].rl);
        rad.pb(c[i].rb);
    }
    sort(rad.begin(), rad.end());
    int curr = 1;
    for (int r : rad) {
        if (newrad.count(r)) continue;
        newrad[r] = curr;
        curr++;
    }
    for (int i = 0; i < n; ++i) {
        c[i].rl = newrad[c[i].rl];
        c[i].rb = newrad[c[i].rb];
    }

    sort(c, c + n, comp);

    /*for (int i = 0; i < n; ++i) {
        cout << c[i].rb << ' ' <<c[i].rl << ' ' <<c[i].h <<endl;
    }*/

    ll ans[max_n];
    for (int i = 0; i < n; ++i)
    {
        ans[i] = get_max(c[i].rb - 1) + c[i].h;
        upd(c[i].rl, ans[i]);
    }
    ll ANS = 0;
    for (int i = 0; i < n; ++i) {
        ANS = max(ANS, ans[i]);
    }
    cout << ANS;
    return 0;
}