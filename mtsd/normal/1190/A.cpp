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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    rep(i,m){
        cin >> a[i];
    }
    ll id = 0;
    ll cnt = 0;
    ll res = 0;
    while(1){
        if(id==m)break;
        ll s = a[id];
        s -= cnt;
        ll num = (s-1)/k+1;
        ll tid = lower_bound(a.begin(),a.end(),num*k+1+cnt)-a.begin();
        //cerr << tid << " " <<num << " " << k << " " << cnt << " " << num*k+1+cnt << endl;
        cnt += tid-id;
        
        id =tid;
        res++;
    }
    cout << res << endl;
    return 0;
}