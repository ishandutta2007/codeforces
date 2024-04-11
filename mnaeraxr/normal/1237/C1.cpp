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

    vector<int> used(n);

    for (int i = 0; i < n; ++i){
        if (used[i]) continue;

        int answer = oo;
        int target = -1;

        for (int j = i + 1; j < n; ++j){
            if (used[j]) continue;

            int cur = p[i].dist(p[j]);

            if (cur < answer){
                answer = cur;
                target = j;
            }
        }

        used[i] = true;
        used[target] = true;

        cout << p[i].ix << " " << p[target].ix << endl;
    }

    return 0;
}