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
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    k*=8;
    k/=n;
    ll s = 1;
    rep(i,k){
        s*=2;
        if(s>=1000000002)break;
    }
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    vector<int>p;
    int c = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            c++;
        }else{
            if(a[i]==a[i-1]){
                c++;
            }else{
                p.push_back(c);
                c = 1;
            }
        }
    }
    p.push_back(c);
    int m = p.size();
    if(m<=s){
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    ll ma = 0;
    for(int i=0;i<m;i++){
        cnt += p[i];
        if(i>=s){
            cnt -= p[i-s];
        }
        ma = max(cnt,ma);
    }
    cout << n-ma << endl;
    return 0;
}