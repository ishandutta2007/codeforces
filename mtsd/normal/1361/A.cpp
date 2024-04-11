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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> s(n);
    priority_queue<pair<int,int>,vector<pii>,greater<pii> > pq;
    rep(i,n){
        int a;
        cin >> a;
        pq.push(MP(a,i));
    }
    vector<int> res;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int id = x.second;
        int k = x.first;
        set<int> st;
        for(auto y:g[id]){
            st.insert(s[y]);
        } 
        bool flag = 1;
        for(int i=1;i<=k-1;i++){
            if(st.count(i)==0){
                flag = 0;
                break;
            }
        }
        if(flag){
            if(st.count(k)==0){
                res.push_back(id);
                s[id] = k;
            }else{
                cout << -1 << "\n";
                return 0;    
            }
        }else{
            cout << -1 << "\n";
            return 0;
        }
    }
    for(auto x:res){
        cout << x+1 << " ";
    }
    cout << "\n";
    return 0;
}