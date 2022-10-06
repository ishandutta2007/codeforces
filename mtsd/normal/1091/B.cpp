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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    vector<int>x(n),y(n);
    vector<int>a(n),b(n);
    map<pair<int,int>,int> mp;
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    rep(i,n){
        rep(j,n){
            mp[MP(x[i]+a[j],y[i]+b[j])]++;
        }
    }
    for(auto x:mp){
        if(x.second==n){
            cout << x.first.first << " " << x.first.second << endl;
            return 0;
        }
    }
    return 0;
}