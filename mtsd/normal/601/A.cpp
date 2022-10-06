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
int d[401][401];
bool flag[401];
int p[401];
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        d[a][b] = 1;
        d[b][a] = 1;  
    }
    rep(i,n)p[i] = inf;
    int used = 1 -d[0][n-1];
    queue<int> q;
    q.push(0);
    p[0] = 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        rep(i,n){
            if(x!=i&&d[x][i]==used&&flag[i]==0){
                q.push(i);
                p[i] = p[x] + 1;
                flag[i] = 1;
            }
        }
    }
    if(p[n-1]==inf){
        cout << -1 << endl;
    }else{
        cout << p[n-1] << endl;
    }
    return 0;
}