#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

int64 f(int64 n){
    return n * (n - 1) / 2;
}


int64 get(int64 n){
    int64 l = 0, h = 100000LL;
    while (l + 1 < h){
        int64 m = (l + h) >> 1;
        if (f(m) <= n) l = m;
        else h = m;
    }
    return l;
}

bool ans[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int64 a, b, c, d;
    cin >> a >> b >> c >> d;

    if (!a && !b && !c && !d){
        cout << 1 << endl;
        return 0;
    }

    int64 t0 = get(a);
    int64 t1 = get(d);
    int64 tt = get(a + b + c + d);

    if (!a){
        if (!b && !c) t0 = 0;
        else t0 = 1;
    }

    if (!d){
        if (!b && !c) t1 = 0;
        else t1 = 1;
    }

    if ((f(t0) != a) || (f(t1) != d) || (f(tt) != (a + b + c + d)) || (t0 + t1 != tt)){
        cout << "Impossible" << endl;
        return 0;
    }

    int64 inv = c;

    for (int i = t0 - 1, m = t1; i >= 0; i--){
        if (inv > m){
            ans[i + m] = true;
            inv -= m;
        }
        else{
            ans[i + inv] = true;
            inv = 0;
        }
    }

    if (inv){
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 0; i < tt; ++i)
        if (ans[i]) cout << "0";
        else cout << "1";

    cout << endl;


    return 0;
}