#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

struct XY
    {
    int x, y;

    XY (int x_, int y_)
    :
    x(x_),
    y(y_) {}

    XY ()
    :
    x(0),
    y(0) {}

    operator< (XY over) const
        {
        if (x != over.x) return x < over.x;
        return y < over.y;
        }
    };

set<XY> ansers;


void print_way (XY p1, XY p2)
    {
    XY cur;
    cur.x = p1.x;
    cur.y = p1.y;

    int dx = 1, dy = 1;
    if (p2.x < p1.x) dx = -1;
    if (p2.y < p1.y) dy = -1;

    while (cur.x != p2.x)
        {


        ansers.insert(cur);

        cur.x+= dx;
        }

    while (cur.y != p2.y)
        {
        ansers.insert(cur);

        cur.y+= dy;
        }
    }


int main()
    {
    FAST;

    XY a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);


    ansers.insert(a);
    ansers.insert(b);
    ansers.insert(c);

    print_way(a, b);
    print_way(c, b);

    cout << ansers.size() << endl;

    for (auto it = ansers.begin(); it != ansers.end(); ++it)
        {
        cout << it->x << " " << it->y << endl;
        }

    return 0;
    }