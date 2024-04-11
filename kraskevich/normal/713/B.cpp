#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

bool inside(int a, int b, int x) {
    return a <= x && x <= b;
}

#define x1 dnjkvbkfd
#define y1 dslknvkl
int n;
int x1 = 2, y1 = 2, x2 = 2, y2 = 2;
int xx1 = 3, yy1 = 4, xx2 = 3, yy2 = 5;

int ask(int lx, int ly, int rx, int ry) {
    assert (lx <= rx);
    assert (ly <= ry);
    cout << "? " << lx << " " << ly << " " << rx << " " << ry << endl;
    int x;
    cin >> x;
    return x;
    int ans = 0;
    if (inside(lx, rx, x1) && inside(lx, rx, x2) && inside(ly, ry, y1) && inside(ly, ry, y2))
        ans++;
    if (inside(lx, rx, xx1) && inside(lx, rx, xx2) && inside(ly, ry, yy1) && inside(ly, ry, yy2))
        ans++;
    return ans;
}

vector<int> find_one(int LX, int LY, int RX, int RY) {
    int l = LX - 1;
    int r = RX;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(LX, LY, m, RY))
            r = m;
        else
            l = m;
    }
    int rx = r;
    l = LY - 1;
    r = RY;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(LX, LY, RX, m))
            r = m;
        else
            l = m;
    }
    int ry = r;
    l = LX;
    r = RX + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(m, LY, RX, RY))
            l = m;
        else
            r = m;
    }
    int lx = l;
    l = LY;
    r = RY + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(LX, m, RX, RY))
            l = m;
        else
            r = m;
    }
    int ly =  l;
    return {lx, ly, rx, ry};
}
   
int main() {
    cin >> n;
    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(1, 1, m, n) != 0)
            r = m;
        else
            l = m;
    }
    vector<int> v;
    vector<int> u;
    l++;
    if (ask(1, 1, l, n) == 1 && ask(l + 1, 1, n, n)) {
        v = find_one(1, 1, l, n);
        u = find_one(l + 1, 1, n, n);
    } else {
        l = 0;
        r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(1, 1, n, m) != 0)
                r = m;
            else
                l = m;
        }
        l++;
        assert (ask(1, 1, n, l) == 1 && ask(1, l + 1, n, n) == 1);
        v = find_one(1, 1, n, l);
        u = find_one(1, l + 1, n, n);
    }
    cout << "! ";
    for (int x : v)
        cout << x << " ";
    for (int x : u)
        cout << x << " ";
    cout << endl;
}