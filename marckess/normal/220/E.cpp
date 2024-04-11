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
typedef pair<ii, int> iii;

struct BIT {
    vi ft;

    BIT () {}
    BIT (int n) : ft(n) {}

    void update (int i, int x) {
        while (i < ft.size()) {
            ft[i] += x;
            i += i & -i;
        }
    }

    int getSum (int i) {
        int sum = 0;
        while (i) {
            sum += ft[i];
            i -= i & -i;
        }
        return sum;
    }

    int query (int a, int b) {
        if (!b)
            return 0;
        return getSum(b) - getSum(a-1);
    }
};

const int MX = 100005;
int n, a[MX];
ll k, res = 0, acu = 0;
vi con;
BIT ini, fin;
int i, j;

void insert (int ind, BIT &in) {
    acu += ini.query(a[ind] + 1, con.size() + 2);
    acu += fin.query(1, a[ind] - 1);
    in.update(a[ind], 1);
}

void delet (int ind, BIT &in) {
    acu -= ini.query(a[ind] + 1, con.size() + 2);
    acu -= fin.query(1, a[ind] - 1);
    in.update(a[ind], -1);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        con.push_back(a[i]);
    }

    sort(con.begin(), con.end());
    con.erase(unique(con.begin(), con.end()), con.end());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(con.begin(), con.end(), a[i]) - con.begin() + 1;

    ini = BIT(con.size() + 5), fin = BIT(con.size() + 5);

    i = 0, j = n;
    while (i < n) {
        insert(i, ini);

        while (j > i && acu <= k) {
            j--;
            insert(j, fin);
        }

        while ((j < n && acu > k) || j <= i) {
            delet(j, fin);
            j++;
        }

        res += n - j;
        i++;
    }

    cout << res << endl;

    return 0;
}