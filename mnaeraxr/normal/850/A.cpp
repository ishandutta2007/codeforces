#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct point{
    vector<int> val;

    point operator-(const point &p) const{
        point ans;
        for (int i = 0; i < 5; ++i)
            ans.val.push_back(val[i] - p.val[i]);
        return ans;
    }

    int operator*(const point &p)const{
        int ans = 0;
        for (int i = 0; i < 5; ++i)
            ans += p.val[i] * val[i];
        return ans;
    }

    // int dim(){
    //     int ans = 0;
    //     for (auto x : val){
    //         if (x >= 0) ans |= 1;
    //         ans <<= 1;
    //     }
    //     return ans;
    // }
};

point read(){
    point p;

    for (int i = 0; i < 5; ++i){
        int v; cin >> v;
        p.val.push_back(v);
    }

    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<point> P;

    for (int i = 0; i < n; ++i){
        auto cur = read();
        P.push_back(cur);
    }

    if (n > 33){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;

    for (int i = 0; i < n; ++i){
        bool good = true;
        for (int j = 0; j < n && good; ++j){
            if (j == i) continue;

            for (int k = j + 1; k < n && good; ++k){
                if (k == i) continue;
                point a = P[j] - P[i], b = P[k] - P[i];
                if (a * b > 0)  good = false;
            }
        }

        if (good) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << endl;

    return 0;
}