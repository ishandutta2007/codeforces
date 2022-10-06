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
    int n,m;
    scanf("%d",&n);
    map<int,int>mp;
    int a,b;
    rep(i,n){
        scanf("%d %d",&a,&b);
        mp[a] = b;
    }
    scanf("%d",&m);
    rep(i,m){
        scanf("%d %d",&a,&b);
        mp[a] = max(mp[a],b);
    }
    ll ans = 0;
    for(auto x:mp){
        ans +=(ll)x.second;
    }
    cout << ans << endl;
    return 0;
}