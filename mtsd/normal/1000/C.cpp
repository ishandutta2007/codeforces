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
    map<ll,int>mp;
    vector<ll>a;
    scanf("%d",&n);
    rep(i,n){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        mp[x]++;
        mp[y+1]--;
        a.PB(x);
        a.PB(y+1);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vector<ll>ans(n+1);
    int tmp = 0;
    for(int i=0;i<a.size();i++){
        tmp += mp[a[i]];
        if(i!=(int)a.size()-1){
            ans[tmp] += a[i+1]-a[i];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld",ans[i]);
        if(i!=n){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}