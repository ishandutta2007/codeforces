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

struct trie {
    map<int, trie*> sig;
    int mx;

    trie () : mx(-1) {}

    int insert (int i, int j, vi &v) {
        if (i == v.size()) {
            int d = mx;
            mx = j;
            return d;
        }

        if (sig.find(v[i]) == sig.end())
            sig[v[i]] = new trie();

        return sig[v[i]]->insert(i+1, j, v);
    }
};

const int MX = 5005, MN = 10100;
trie *neg = new trie(), *pos = new trie();

int res[MX], a[MX], d[MX], n, acu;
vi pr;
bitset<MN> bs;

void criba () {
    for (ll i = 2; i < MN; i++) {
        if (!bs[i]) {
            pr.push_back(i);
            for (ll j = i * i; j < MN; j += i)
                bs[j] = 1;
        }
    }
}

vi fac (ll n) {
    vi res;

    for (int i = 0; i < pr.size() && ll(pr[i]) * pr[i] <= n; i++) {
        int pw = 0;
        while (n % pr[i] == 0) {
            pw++;
            n /= pr[i];
        }
        if (pw & 1)
            res.push_back(pr[i]);
    }

    if (n > 1)
        res.push_back(n);

    return res;
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);

    for (int i = 0; i < n; i++) {
        vi v = fac(abs(a[i]));

        if (a[i] == 0)
            d[i] = n;
        else if (a[i] > 0)
            d[i] = pos->insert(0, i, v);
        else
            d[i] = neg->insert(0, i, v);
    }

    for (int i = 0; i < n; i++) {
        acu = 0;

        for (int j = i; j < n; j++) {
            if (d[j] < i)
                acu++;
            res[max(1, acu)]++;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", res[i]);
    printf("\n");

    return 0;
}