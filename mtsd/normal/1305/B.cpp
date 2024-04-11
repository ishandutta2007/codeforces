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
    string s;
    cin >> s;
    vector<vector<int> > ans;
    while(1){
        string t;
        int n = s.size();
        vector<int>a,b;
        rep(i,n){
            if(s[i]=='(')a.push_back(i);
            else b.push_back(i);
        }
        int m = min((int)a.size(),(int)b.size());
        vector<int> res;
        rep(i,m){
            if(a[i]<b[(int)b.size()-1-i]){
                res.push_back(a[i]);
                res.push_back(b[(int)b.size()-1-i]);
            }
        }
        sort(res.begin(),res.end());
        vector<bool> p(n);
        rep(i,res.size()){
            p[res[i]] = true;
        }
        rep(i,n){
            if(!p[i]){
                t.push_back(s[i]);
            }
        }
        if(res.size()==0){
            break;
        }else{
            ans.push_back(res);
        }
        s = t;
    }
    cout << ans.size() << "\n";
    rep(i,ans.size()){
        cout << ans[i].size() <<"\n";
        for(auto x:ans[i]){
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}