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
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> a(n);
    rep(i,n){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    a.push_back(1000000000);
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = *upper_bound(a.begin(),a.end(),a[i]);
        if(a[i]+k>=x){
            ans++;
        }
    }
    printf("%d\n",n-ans);
    return 0;
}