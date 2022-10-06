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
set<string> st[7];
vector<string> p[6];
int n;
void dfs(int id,string t){
    if(st[id].count(t))return;
    if(id==n){
        st[id].insert(t);
        return;
    }
    st[id].insert(t);
    int k = t[id-1]-'a';
    t.pop_back();
    for(auto x:p[k]){
        t += x;
        dfs(id+1,t);
        t.pop_back();
        t.pop_back();
    }
}

int main(){
    int q;
    cin >> n >> q;
    rep(i,q){
        char c;
        string s;
        cin >> s >> c;
        reverse(s.begin(),s.end());
        p[c-'a'].push_back(s);
    }
    string t = "a";
    dfs(1,t);
    cout << st[n].size() << endl;
    return 0;
}