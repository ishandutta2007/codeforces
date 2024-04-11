#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
int t, n, u, r, d, l;

void solve() {
    cin >> n >> u >> r >> d >> l;
    int ar[4];
    for (int j = 0; j < 16; j++) {
        ar[0]=u;
        ar[1]=r;
        ar[2]=d;
        ar[3]=l;
        bool works=true;
        for (int i = 0; i < 4; i++) {
            int nx = (i+1)%4;
            if (j & (1<<i)) {
                ar[i]--;
                ar[nx]--;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (ar[i]<0 || ar[i]>n-2) {
                works=false;
                break;
            }
        }
        if(works) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
//    vector<bool> take(4, false);
//    for (int i = 0; i < 4; i++) {
//        if (ar[i]==n) {
//            if (ar[nx]==0 || ar[pr]==0) {
//                cout << "NO\n";
//                return;
//            }
//            ar[i] -= 2;
//            ar[nx]--;
//            ar[pr]--;
//            take[i]=true;
//            take[pr]=true;
//        }
//    }
//    for (int i = 0; i < 4; i++) {
//        int nx = (i+1)%n;
//        int pr = (i+3)%n;
//        if (ar[i]==n-1) {
//            if ((! take[i]) && ar[nx]>0) {
//                ar[i]--;
//                ar[nx]--;
//                take[i]=true;
//            } else if ((! take[pr]) && ar[pr]>0) {
//                ar[i]--;
//                ar[pr]--;
//                take[pr]=true;
//            } else {
//                cout << "NO\n";
//                return;
//            }
//        }
//        for (int j = 0; j < 4; j++) cout << ar[j] << ' ';
//        cout << '\n';
//    }
//    cout << "YES\n";
//    return;
//    int ar[8];
//    F0R(i, 8) {
//        if (i%2!=0) ar[i]=1;
//        else ar[i]=n-2;
//    }
//    ar[0] -= u;
//    ar[2] -= r;
//    ar[4] -= d;
//    ar[6] -= l;
//    for (int i = 1; i < 8; i += 2) {
//        if (ar[(i+1)%8]==-2 || ar[(i-1)%8]==-2) {
//            ar[i]--;
//            ar[(i+1)%8]++;
//            ar[(i-1)%8]++;
//        }
//    }
//    for (int i = 1; i < 8; i += 2) {
//        if (ar[i]==1 && (ar[(i+1)%8]==-1 || ar[(i-1)%8]==-1) && ar[(i+1)%8]<n-2 && ar[(i-1)%8]<n-2) {
//            ar[i]--;
//            ar[(i+1)%8]++;
//            ar[(i-1)%8]++;
//        }
//    }
//    for (int i = 0; i < 8; i += 2) {
//        if (ar[i]<0 || ar[i]>n-2) {
//            cout << "NO\n";
//            return;
//        }
//    }
//    cout << "YES\n";
//    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}