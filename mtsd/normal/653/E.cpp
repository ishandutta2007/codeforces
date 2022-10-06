#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
set<pair<int,int> > st;
bool flag[300010];
set<int>p;
int dfs(int id){
    p.erase(id);
    if(p.size()==0)return 0;
    auto x = p.begin();
    int k = *x;
    int c = 0;
    while(x!=p.end()){
        if(st.count(MP(id,k))==0){
            c++;
            dfs(k);
        }
        x = p.upper_bound(k);
        k = *x;
    }
    return c;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,n)p.insert(i);
    int sss = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(a==0||b==0)sss++;
        st.insert(MP(a,b));
        st.insert(MP(b,a));
    }
    if(sss >n-1-k){
        cout << "impossible\n";
        return 0;
    }
    int c = dfs(0);
    if(c>k||p.size()!=0){
        cout << "impossible\n";
        return 0;
    }
    cout << "possible\n";
    return 0;
}