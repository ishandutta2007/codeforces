#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define REP(i,a) for (int i = 0; i < (a); i++)
#define add push_back
using namespace std;
 
int ni() {
    int x; cin >> x;
    return x;
}
 
ll nl() {
    ll x; cin >> x;
    return x;
}
 
double nd() {
    double x; cin >> x;
    return x;
}
 
string next() {
    string x; cin >> x;
    return x;
}
 
 
ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)&3;
}
 
ll boundary(ll x1, ll y1, ll x2, ll y2) {
    return __gcd(abs(x1-x2),abs(y1-y2))&3;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int N = ni();
 
    vector<pll> nums;
    vector<pii> mods;
    REP(i,N) {
        ll x = nl();
        ll y = nl();
        nums.add({x,y});
        mods.add({(int)(x&3),(int)(y&3)});
    }
 
    const int MAX_N = 6000;
 
    int cnt[MAX_N][4][4][4] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int b = (int)boundary(nums[i].first,nums[i].second,nums[j].first,nums[j].second);
            cnt[i][mods[j].first][mods[j].second][b] += 1;
            cnt[j][mods[i].first][mods[i].second][b] += 1;
        }
    }
 
    ll eee = 0;
    ll ooe = 0;
    for (int i = 0; i < N; i++) {
        for (int b1 = 0; b1 < 4; b1++) {
            for (int b2 = b1; b2 < 4; b2 += 2) {
                for (int s1 = 0; s1 < 16; s1++) {
                    int firsts2 = (b1<b2) ? 0 : s1;
                    for (int s2 = firsts2; s2 < 16; s2++) {
                        int x1 = s1/4;
                        int y1 = s1%4;
                        int x2 = s2/4;
                        int y2 = s2%4;
                        if (x1%2 != x2%2 || y1%2 != y2%2) continue;
 
                        int b3;
                        int triangles;
                        if (x1==x2 && y1==y2) {
                            b3 = 0;
                            if (b1==b2)
                                triangles = cnt[i][x1][y1][b1]*(cnt[i][x1][y1][b2]-1)/2;
                            else
                                triangles = cnt[i][x1][y1][b1]*cnt[i][x1][y1][b2];
                        } else {
                            b3 = 2;
                            triangles = cnt[i][x1][y1][b1]*cnt[i][x2][y2][b2];
                        }
                        int B = (b1+b2+b3)%4;
                        if (area(nums[i].first,nums[i].second,x1,y1,x2,y2) == B) {
                            if (b1%2==0&&b2%2==0)
                                eee += triangles;
                            else
                                ooe += triangles;
                        }
                    }
                }
            }
        }
    }
    ll ans = eee/3+ooe;
    cout << ans << '\n';
}