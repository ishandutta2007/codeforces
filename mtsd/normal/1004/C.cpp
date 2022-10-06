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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>a(n),l(n+1,-1),r(n+1,-1);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n){
        if(l[a[i]]==-1){
            l[a[i]] = i;
        }
        r[a[i]] = i;
    }
    vector<int> v;
    rep(i,n+1){
        if(r[i]!=-1){
            v.PB(r[i]);
        }
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    rep(i,n+1){
        if(l[i]!=-1){
            ans += v.end()-upper_bound(v.begin(),v.end(),l[i]);
        }
    }
    cout <<ans << endl;
    return 0;
}