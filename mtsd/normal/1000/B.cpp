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
    scanf("%d %d",&n,&m);
    vector<int> a(n+2),b(n+2),c(n+2);
    a[0] = 0;
    a[n+1] = m;
    rep(i,n)scanf("%d",&a[i+1]);
    int ans = 0;
    rep(i,n+2){
        if(i%2==0){
            if(i!=n+1){
                ans += a[i+1]-a[i];
            }
        }
    }
    rep(i,n+2){
        if(i%2==1){
            b[i] = (a[i]-a[i-1]);
            if(i>=3){
                b[i] += b[i-2];
            }
            c[i] = ans-b[i];
        }
    }
    rep(i,n+2){
        if(i%2==1){
            ans = max(ans,b[i]-1+m-a[i]-c[i]);
        }
    }
    cout << ans << endl;
    return 0;
}