#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int n;
vi a;
bool up;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    up=true;
    F0R(i, n) {
        if (a[i]%2==0) a[i] /= 2;
        else {
            if (up) a[i]++;
            else a[i]--;
            a[i] /= 2;
            up = !up;
        }
        cout << a[i] << endl;
    }
}