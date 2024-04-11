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

template<typename T>
vector<T> divisor(T n)
{
    vector<T> res;
    for(T i=1;(long long)i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i != n/i){
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> v = divisor(n);
    vector<ll> ans;
    for(auto x:v){
        ll t = n/x;
        ll tmp = (n-x)*(t)/2;
        ans.push_back(t+tmp);
    }
    sort(ans.begin(),ans.end());
    int m = ans.size();
    for(int i=0;i<m;i++){
        cout << ans[i];
        if(i!=m-1){
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}