
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<ll>
#define x real()
#define y imag()

istream &operator>>(istream &is, pt &p) {
    ll X, Y;
    cin >> X >> Y;
    p = {X, Y};
    return is;
}

pt p[6];
vector<ll> vx, vy;
bool arr[50][50];

int put(pt p1, pt p2) {
    int i1 = find(vx.begin(), vx.end(), p1.x) - vx.begin();
    int j1 = find(vy.begin(), vy.end(), p1.y) - vy.begin();
    int i2 = find(vx.begin(), vx.end(), p2.x) - vx.begin();
    int j2 = find(vy.begin(), vy.end(), p2.y) - vy.begin();
    int cnt = 0;
    for(int i = i1; i < i2; i++) {
        for(int j = j1; j < j2; j++) {
            if(!arr[i][j]) {
                cnt++;
                arr[i][j] = true;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 6; i++) {
        cin >> p[i];
        vx.push_back(p[i].x);
        vy.push_back(p[i].y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    put(p[4], p[5]);
    put(p[2], p[3]);
    cout << (put(p[0], p[1]) ? "YES" : "NO") << endl;
}