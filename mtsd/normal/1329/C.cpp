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

int h,g;
void dfs(int id,int dep,vector<int>&a,vector<bool>&flag){
    int left = id*2;
    int right = id*2+1;
    // cerr << id << " " << left << " " << right << endl;
    if(a[left]==0&&a[right]==0){
        a[id] = 0;
        return;
    }
    if(a[left]<a[right]){
        a[id] = a[right];
        dfs(right,dep+1,a,flag);
    }else if(a[right]<a[left]){
        a[id] = a[left];
        dfs(left,dep+1,a,flag);
    }
    if(dep==g&&a[left]==0&&a[right]==0){
        flag[id] = 1;
    }
    if(a[left]<a[right]){
        if(flag[right])flag[id] = 1;
    }else if(a[right]<a[left]){
        if(flag[left])flag[id] = 1;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        cin >> h >> g;
        vector<int> a((1<<(h+1))+3);
        vector<bool> flag((1<<(h+1))+3);
        rep(i,(1<<(h))-1)cin >> a[i+1];
        vector<int> p;
        rep(i,(1<<g)){
            int id = i+1;
            int d = 0;
            while(id!=0){
                id /= 2;
                d++;
            }    
            while(flag[i+1]==0&&a[i+1]!=0){
                dfs(i+1,d,a,flag);
                p.push_back(i+1);
                // cerr << i+1 << endl;
                // rep(i,(1<<h)){
                //     cerr << a[i+1] << " ";
                // }
                // cerr << endl;
                // rep(i,(1<<h)){
                //     cerr << flag[i+1] << " ";
                // }
                // cerr << endl;
            }
        }
        ll sm = 0;
        rep(i,(1<<g)){
            int id = i+1;
            sm += a[id];
        }
        cout << sm << "\n";
        for(auto x:p){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}