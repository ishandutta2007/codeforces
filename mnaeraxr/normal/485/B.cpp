#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl
#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
const int oo = 1 << 30;

vector<pii> V;
int ANS[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int mx, Mx, my, My;
    cin >> mx >> my;
    Mx = mx, My = my;
    for (int i = 1; i < n; ++i){
        int x, y; cin >> x >> y;
        mx = min(mx, x), Mx = max(Mx, x);
        my = min(my, y), My = max(My, y);
    }
    int l = max(Mx - mx, My - my);
    cout << 1LL * l * l << endl;


    return 0;
}