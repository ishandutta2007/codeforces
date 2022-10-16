#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

map<set<int>,int> grund;

int grundy(set<int> v){
    if (v.empty()) return 0;
    if (grund.count(v))
        return grund[v];

    int &ans = grund[v];

    set<int> s;

    for (int i = 1; i <= *v.rbegin(); ++i){
        set<int> t;
        for (auto x : v){
            if (i > x) t.insert(x);
            else if (i < x) t.insert(x - i);
        }
        s.insert( grundy(t) );
    }

    while (s.count(ans))
        ans++;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    map<int,set<int>> freq;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;

        for (int j = 2; j * j <= v; ++j){
            if (v % j == 0){
                int f = 0;
                while (v % j == 0){
                    f++;
                    v /= j;
                }
                freq[j].insert(f);
            }
        }

        if (v > 1)
            freq[v].insert(1);
    }

    int x = 0;
    for (auto ff : freq)
        x ^= grundy(ff.second);

   // cout << x << endl;

    cout << (x ? "Mojtaba" : "Arpa") << endl;

    return 0;
}