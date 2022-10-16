#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
 
struct point {
    int x, y, z, ix;
 
    bool operator<(const point &p) const {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        if (z != p.z) return z < p.z;
        return false;
    }
 
    int dist(point &p){
        return abs(x - p.x) + abs(y - p.y) + abs(z - p.z);
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
 
    vector<point> p;
 
    for (int i = 0; i < n; ++i){
        int x, y, z; cin >> x >> y >> z;
        p.push_back({x, y, z, i + 1});
    }
 
    sort(p.begin(), p.end());
 
    // for (auto pp : p){
    //     cout << pp.x << " " << pp.y << " " << pp.z << " " << pp.ix << endl;
    // }
 
    int extra_x = 0, extra_y = 0, extra_z = 0;
 
    auto add = [&](int &extra, int v){
        if (extra){
            cout << extra << " " << v << endl;
            extra = 0;
        } else {
            extra = v;
        }
    };
 
    for (int i = 0, j, k; i < n; i = j){
        for (j = i; j < n && p[i].x == p[j].x; j = k){
            for (k = j; k < n && p[k].y == p[j].y && p[k].x == p[j].x; ++k){
                add(extra_z, p[k].ix);
            }
 
            if (extra_z){
                add(extra_y, extra_z);
                extra_z =  0;
            }
        }
 
        if (extra_y){
            add(extra_x, extra_y);
            extra_y = 0;
        }
    }
 
    return 0;
}