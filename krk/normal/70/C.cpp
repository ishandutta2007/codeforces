#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int maxx, maxy, w;
map <pair <int, int>, vector <int> > M;
int BIT[Maxn];
int bx = Maxn, by = Maxn;

int Rev(int x)
{
    int res = 0;
    while (x) {
          res = 10 * res + x % 10;
          x /= 10;
    }
    return res;
}

int gcd(int x, int y)
{
    if (!x) return y;
    else return gcd(y % x, x);
}

pair <int, int> getPair(int x, int y)
{
     int g = gcd(x, y);
     return make_pair(x / g, y / g);
}

void Insert(int x)
{
     for (int i = x; i < Maxn; i += i & -i)
         BIT[i]++;
}

int Get(int x)
{
     int res = 0;
     for (int i = x; i > 0; i -= i & -i)
         res += BIT[i];
     return res;
}

void getBest(int l, int r, int &res)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     if (Get(mid) >= w) {
                  res = mid;
                  getBest(l, mid - 1, res);
     } else getBest(mid + 1, r, res);
}

int main()
{
    cin >> maxx >> maxy >> w;
    for (int j = 1; j <= maxy; j++) M[getPair(Rev(j), j)].push_back(j);
    for (int i = 1; i <= maxx; i++) {
        vector <int> V = M[getPair(i, Rev(i))];
        for (int j = 0; j < V.size(); j++) Insert(V[j]);
        int j = -1;
        getBest(1, maxy, j);
        if (j != -1 && ll(i) * ll(j) < ll(bx) * ll(by)) {
              bx = i; by = j;
        }
    }
    if (bx == Maxn) cout << "-1\n";
    else cout << bx << " " << by << endl;
    return 0;
}