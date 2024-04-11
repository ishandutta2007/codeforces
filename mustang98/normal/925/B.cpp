#include <bits/stdc++.h>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define time privet5
#define left privet6

using namespace std;
typedef long long ll;

const int max_n = 300011, log_n = 32, max_m = 111, mod = 1000000007, inf = 1011111111;

int x, y, used[max_n], n;
pair<int, int> a[max_n], xx, yy;


int operate(int x, int ind) {
    int k = 1;
    while (ind >= 0) {
        if (1LL * a[ind].F * k >= x) {
            return ind - 1;
        }
        --ind;
        ++k;
    }
    return -2;
}

bool check(int x, int y) {
    int ind = operate(y, n - 1);
    if (ind == -2) return false;
    yy = make_pair(ind + 1, n - 1);
    int ind1 = operate(x, ind);
    if (ind1 == -2) return false;
    xx = make_pair(ind1 + 1, ind);
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> y;
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }
    sort(a, a + n);
    bool ans = check(x, y);
    if (!ans) {
        ans = check(y, x);
        swap(xx, yy);
    }
    if (ans) {
        cout << "Yes" << endl;
        cout << xx.S - xx.F + 1 << " " << yy.S - yy.F + 1 << endl;
        for (int i = xx.F; i <= xx.S; ++i) {
            cout << a[i].S + 1 << " ";
        }
        cout << endl;
        for (int i = yy.F; i <= yy.S; ++i) {
            cout << a[i].S + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}