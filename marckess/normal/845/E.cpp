#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m, k, x[505], y[505], q[505];
vi a, b, c, d;

void impr () {
    for (int x : a)
        cout << x << " ";
    cout << endl;
    for (int x : b)
        cout << x << " ";
    cout << endl;
    for (int x : c)
        cout << x << " ";
    cout << endl;
    for (int x : d)
        cout << x << " ";
    cout << endl << endl;
}

void shift (vi &a, vi &b, vi &c, vi &d) {
    vi temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;

    for (int i = 0; i < k; i++)
        d[i] = n - d[i] + 1;
    for (int i = 0; i < k; i++)
        b[i] = n - b[i] + 1;
    swap(n, m);

   //impr();
}

int obtPrim () {
    vi o(1, 1);
    for (int i = 0; i < k; i++)
        o.push_back(c[i]+1);

    sort(o.begin(), o.end());
    o.erase(unique(o.begin(), o.end()), o.end());

    iota(q, q+k, 0);
    sort(q, q+k, [&] (int x, int y) {
        return b[x] < b[y];
    });

    for (int l : o) {
        int mx = 0;

        for (int i = 0; i < k; i++) {
            int u = q[i];

            if (a[u] <= l && l <= c[u]) {
                if (b[u] > mx + 1)
                    return l;
                mx = max(mx, d[u]);
            }
        }

        if (mx < m)
            return l;
    }

    return -1;
}

bool esPos (int mit) {
    for (int i = 0; i < k; i++) {
        a[i] = max(1, y[i] - mit);
        b[i] = max(1, x[i] - mit);
        c[i] = min(n, y[i] + mit);
        d[i] = min(m, x[i] + mit);
    }

    //impr();
    int aba = obtPrim();
    
    shift(a, b, c, d);
    int izq = obtPrim();

    shift(a, b, c, d);
    int arr = obtPrim();
    if (arr != n + 1)
        arr = n - arr + 1;

    shift(a, b, c, d);
    int der = obtPrim();
    if (der != n + 1)
        der = n - der + 1;
    swap(n, m);

    //cout << aba << " " << izq << " " << arr << " " << der << endl;

    return mit * 2 + 1 >= max(abs(izq - der) + 1, abs(arr - aba) + 1);
}

int obtRes () {
    int i = 0, j = 1e9+5, m = (i+j)/2, res = 32;

    while (res--) {
        if (esPos(m))
            j = m;
        else
            i = m;
        m = (i+j)/2;
    }

    if (esPos(i))
        return i;
    return j;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> y[i] >> x[i];
    a = b = c = d = vi(k);

    cout << obtRes() << endl;

    return 0;
}