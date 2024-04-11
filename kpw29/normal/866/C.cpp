#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

double expected;
vector<tuple<int,double,int> > tricks;
int n, r, m;
double mem[52][10100];
bool comp[52][10100];

double dp(int at, int t) {
    if (t >= r) {
        return t+expected;
    }
    if (at == (int)tricks.size()) {
        return t;
    }

    ii st(at,t);
    if (comp[at][t]) {
        return mem[at][t];
    }

    auto [curt, prob, penalty] = tricks[at];
    int nxtt = at + 1 < tricks.size() ? get<0>(tricks[at+1]) : n;
    int walk = (nxtt - curt);

    //double ans = min(t+expected,
    //        prob * (dp(at+1, t + walk)) +
    //        (1 - prob) * min(t+expected, dp(at+1, t + walk + penalty)));
    
    double ans = min(t+expected,
            prob * (dp(at+1, t + walk)) +
            (1 - prob) * min(t+expected+penalty, dp(at+1, t + walk + penalty)));
    comp[at][t] = true;
    return mem[at][t] = ans;
}

int main() {
    srand(time(NULL));
    
    cin >> m >> r; 
    ++r;
	
    rep(i,0,m) {
        int t, add;
        double p;
        int si, fi;
        cin >> fi >> si;
        n += fi;
        t = n;
        int val;
        cin >> val;
        p = (double)(val) / 100;
        
        //cin >> t >> p >> add;
        add = si - fi;
        tricks.emplace_back(t, p, add);
    }
	
    sort(tricks.begin(), tricks.end());

    double lo = 0.0,
           hi = 1e9;
    rep(it,0,100) {
        expected = (lo+hi)/2;
        memset(comp,0,sizeof(comp));
        double t = dp(0,get<0>(tricks[0]));
        if (t > expected) {
            lo = expected;
        } else {
            hi = expected;
        }
    }

    cout << setprecision(12) << lo << endl;
    return 0;
}