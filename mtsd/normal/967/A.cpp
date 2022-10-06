#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

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
    int n,s;
    cin >> n >> s;
    vector<int>h(n),m(n),k(n);
    rep(i,n)cin >> h[i] >> m[i];
    rep(i,n)k[i] = h[i]*60+m[i];
    if(k[0]>=s+1){
        cout << "0 0" << endl;
        return 0;
    }
    bool flag = 0;
    int ans =0;
    rep(i,n-1){
        int kkk=k[i]+s+1;
        if(kkk+1+s<=k[i+1]){
            ans = kkk;
            flag = 1;
            break;
        }
    }
    if(flag){
        cout << ans/60 << " " << ans%60 << endl;
    }else{
        ans = k[n-1]+s+1;
        cout << ans/60 << " " << ans%60 << endl;
    }
    return 0;
}