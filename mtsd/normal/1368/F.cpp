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
bool a[1010];
int n;
void q(vector<int>&res){
    cout << res.size() << " ";
    for(auto x:res){
        cout << x+1 << " ";
        a[x] = 1;
    }
    cout << endl;
    int k;
    cin >> k;
    k--;
    rep(i,res.size()){
        int id = (k+i)%n;
        a[id] = 0;
    }
    return;
}
bool ok[2010];
int main(){
    cin >> n;
    if(n<=3){
        cout << 0 << endl;
        return 0;
    }
    int mx = 0;
    int K = 1;
    for(int k=1;k<=n-1;k++){
        int cc = n/(k+1);
        int s = k*cc + (max(0,n-(k+1)*cc-1));
        s -= k;
        if(chmax(mx,s)){
            K = k;
        }
    }
    rep(i,n){
        if(i%(K+1)!=0)ok[i] = 1;
    }
    while(1){
        int c = 0;
        rep(i,n){
            if(a[i])c++;
        }
        if(c==mx)break;
        vector<int>p;
        int cc = 0;
        rep(i,n){
            if(!a[i]){
                if(ok[i]){
                    p.push_back(i);
                    cc++;
                    if(cc==K+1)break;
                }
            }
        }
        q(p);
    }    
    cout << 0 << endl;
    return 0;
}