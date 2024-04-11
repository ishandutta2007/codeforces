#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
using namespace std;

const int N = 2049;

int n, ans[N], z = -1, used[N];
int p1, p2;

vector<int> G;

int get(int a, int b) {
    cout << (G[a] | G[b]) << endl;
    return (G[a] | G[b]);
}


signed main()
{   srand(time(0));
/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> n;
    int a = 1, b = 2, x;
    cout << "? 1 2" << endl;
    cin >> x;
    vi q;
    for (int i = 3; i <= n; i++)
        q.pb(i);
    random_shuffle(all(q));
    for (auto c: q) {
        int res;
        cout << "? " << b << ' ' << c << endl;
        cin >> res;
        if (res == x) {
            b = c;
            cout << "? " << a << ' ' << b << endl;
            cin >> x;
            continue;
        }
        if (res < x)
            a = c, x = res;
    }
    q.clear();
    for (int i = 1; i <= n; i++)
        if (i != a && i != b)
            q.pb(i);
    random_shuffle(all(q));
    int z;
    for (auto x: q) {
        int r1, r2;
        cout << "? " << x << ' ' << a << endl;
        cin >> r1;
        cout << "? " << x << ' ' << b << endl;
        cin >> r2;
        if (r1 == r2)
            continue;
        if (r1 < r2)
            z = a;
        else
            z = b;
        break;
    }
    vi ans;
    for (int i = 1; i <= n; i++)
        if (i == z)
            ans.pb(0);
        else {
            int x;
            cout << "? " << i << ' ' << z << endl;
            cin >> x;
            ans.pb(x);
        }
    cout << "! ";
    for (auto x: ans)
        cout << x << ' ';
    return 0;
}