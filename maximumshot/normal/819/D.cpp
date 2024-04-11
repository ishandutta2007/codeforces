#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int getPhi(int vl) {
    map< int, int > mp;
    for(int x = 2;x * x <= vl;x++) {
        if(vl % x) continue;
        mp[x]++;
        vl /= x;
        x--;
    }
    if(vl > 1) {
        mp[vl]++;
    }
    int res = 1;
    for(pii iter : mp) {
        int dv = iter.first;
        int pw = iter.second;
        int tmp = 1;
        for(int j = 0;j < pw;j++) {
            tmp *= dv;
        }
        res *= (tmp - tmp / dv);
    }
    return res;
}

int T, n, S, RS;
int a[N];
int b[N];
int g;
map< int, vec< pii > > List;

int binpow(int vl, int pw, int md) {
    if(pw == 0) {
        return 1 % md;
    }else {
        int tmp = binpow(vl, pw / 2, md);
        tmp = (1ll * tmp * tmp) % md;
        if(pw % 2) {
            tmp = (1ll * tmp * vl) % md;
        }
        return tmp;
    }
}

int getId(int x) {
    x /= g;
    return (1ll * x * RS) % (T / g);
}

int res[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &T, &n);

    S = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        S = (S + a[i]) % T;
    }

    b[1] = 0;

    for(int i = 2;i <= n;i++) {
        b[i] = (b[i - 1] + a[i]) % T;
    }

    if(S == 0) {
        set< int > have;
        for(int i = 1;i <= n;i++) {
            if(!have.count(b[i])) {
                printf("1 ");
                have.insert(b[i]);
            }else {
                printf("0 ");
            }
        }
        printf("\n");
        return 0;
    }

    g = __gcd(S, T);

    {
        int TT = T / g;
        int SS = S / g;
        int phi = getPhi(TT);
        RS = binpow(SS, phi - 1, TT);
    }

    {
        set< int > have;
        for(int i = 1;i <= n;i++) {
            if(!have.count(b[i])) {
                res[i] = 0;
                have.insert(b[i]);
            }else {
                res[i] = -1;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        if(res[i] != -1) {
            List[b[i] % g].push_back(make_pair(b[i] - b[i] % g, i));
        }
    }

    int ln = T / g;

#ifdef maximumSHOT
    cout << S << " " << T << " " << g << "\n";
    cout << RS << " : " << ((S / g) * RS) % (T / g) << " !\n";

    cout << "b : ";

    for(int i = 1;i <= n;i++) {
        cout << b[i] << " \n"[i == n];
    }

    cout << "res : ";

    for(int i = 1;i <= n;i++) {
        cout << res[i] << " \n"[i == n];
    }

    cout << "\n";
    for(int i = 0;i < T;i++) {
        cout << getId(i) << " ";
    }
    cout << "\n";
#endif

    for(auto iter : List) {
        vec< pii > & arr = iter.second;
        sort(ALL(arr), [](pii x, pii y) {
            return getId(x.first) < getId(y.first);
        });
#ifdef maximumSHOT
        cout << iter.first << " : ";
        for(pii x : arr) {
            if(res[x.second] != -1) {
                cout << getId(x.first) << " ";
            }
        }
        cout << "\n";
#endif
        for(int tmp, j, i = 0;i < (int)arr.size();i++) {
            j = (i + 1) % (int)arr.size();
            tmp = getId(arr[j].first) - getId(arr[i].first);
            tmp = (tmp % ln + ln) % ln;
            if(tmp == 0) tmp = ln;
            if(res[arr[i].second] != -1) {
                res[arr[i].second] = tmp;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", res[i] == -1 ? 0 : res[i]);
    }

    printf("\n");

    return 0;
}