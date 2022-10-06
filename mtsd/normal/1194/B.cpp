#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(zz,q){
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        rep(i,n)cin >> s[i];
        vector<int> a(n);
        vector<int> b(m);
        rep(i,n){
            
            rep(j,m){
                if(s[i][j]!='*')a[i]++;
            }
        }
        rep(i,m){
            rep(j,n){
                if(s[j][i]!='*')b[i]++;
            }
        }
        int ans = inf;
        rep(i,n){
            rep(j,m){
                ans = min(ans,a[i]+b[j]-(s[i][j]=='.'));
            }
        }
        cout << max(0,ans) << endl;
    }
    return 0;
}