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
    cin >> n;
    vector<string> a(n),b(n);
    map<string,int> mpa,mpb;
    set<string>st;
    rep(i,n){
        cin >> a[i];
        mpa[a[i]]++;
        st.insert(a[i]);
    }
    rep(i,n){
        cin >> b[i];
        mpb[b[i]]++;
        st.insert(b[i]);
    }
    int ans = 0;
    for(auto x:st){
        ans += abs(mpa[x]-mpb[x]);
        
    }
    cout << ans/2 << endl;
    return 0;
}