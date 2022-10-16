#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct P{
    int x, y, ix;
};

vector<int> solve(vector<P> ls){
    sort(ls.begin(), ls.end(), [&](P &a, P &b){
        if (a.y != b.y) return a.y > b.y;
        return a.x > b.x;
    });

    // for (auto x : ls)
    //     cout << x.x << " " << x.y << endl;
    // cout << endl;

    vi answer;

    int last = 1000000;

    for (auto p : ls){
        if (p.x < last){
            answer.push_back(p.ix);
            last = p.y;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<P> inc, dec;

    for (int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        P x = {a, b, i + 1};

        if (a > b) dec.push_back(x);
        if (b > a) inc.push_back(x);
    }

    for (auto &u : dec){
        swap(u.x, u.y);
    }

    vi ansi = solve(inc);
    vi ansd = solve(dec);

    reverse(ansd.begin(), ansd.end());

    if (ansd.size() > ansi.size()){
        ansi.swap(ansd);
    }

    cout << ansi.size() << endl;

    for (auto u : ansi)
        cout << u << " ";
    cout << endl;

    return 0;
}