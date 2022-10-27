#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}

int n, m;
int ex, ey;
int sx, sy;
int sp, p;
vector <int> t;
void go(int s, int e, int lim, int frame) {
    int dir = 1;
    //cout << "GO " << s << ' ' << e << ' ' << lim << endl;
    for (int i = 0 ; i < frame ; ++ i) {
       // cout << "S " << s << endl;
        if (s == e) {
            t.push_back(i);
        }
        if (s + dir > lim || s + dir < 1) dir = - dir;
        s += dir;
    }
}

void solve() {

    cin >> n >> m >> sx >> sy >> ex >> ey >> sp;
    int frame = 2 * (n-1) * (m-1);
    t.clear();
    //cout << "ALIVE" << endl;
    go(sx, ex, n, frame);
    go(sy, ey, m, frame);
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
//    cout << "TIMES : ";
//    for (int i : t) {
//        cout << i << ' ';
//    }
//    cout << '\n';
    p = mul(sp, power(100, MOD - 2));
    int f = sub(1, p);
    int sum = 0, cf = 1;
    for (int i = 0; i < t.size() ; ++ i) {
        plusle(sum, mul(p, mul(t[i], cf)));
        cf = mul(cf, f);
    }

    int coeff = sub(1, cf);
    sum = add(sum, mul(cf, frame));
    int L = mul(sum, power(coeff, MOD - 2));
    cout << L << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T-- ;) {
        solve();
    }
}