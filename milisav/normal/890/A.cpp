#include<bits/stdc++.h>
#define STIZE(x) fprintf(stderr, "STIZE%d\n", x);
#define PRINT(x) fprintf(stderr, "%s = %d\n", #x, x);
#define NL(x) printf("%c", " \n"[(x)]);
#define lld long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mid (l+r)/2
#define endl '\n'
#define all(a) begin(a),end(a)
#define sz(a) int((a).size())
#define LINF 1000000000000000LL
#define INF 1000000000
#define EPS 1e-9
using namespace std;

vector<pair<int,int> > a;
int main() {
    for(int i = 0; i < 6; i++){
        int x; cin >> x;
        a.pb(make_pair(x,i));
    }
    do{
       if(a[0].first+a[1].first+a[2].first == a[3].first+a[4].first+a[5].first) {
            cout << "YES";
            return 0;
       }
    }while(next_permutation(all(a)));
    cout << "NO";
    return 0;
    return 0;
}