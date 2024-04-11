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
vector<pair<int,int> > res;
void merge(vector<int>&a,vector<int>&b){
    int n = a.size();
    rep(i,n){
        res.push_back({a[i],b.back()});
        a.push_back(b.back());
        b.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> p(n+1);
    queue<int> q;
    rep(i,n){
        q.push(i+1);
        p[i+1].push_back(i+1);
    }
    while(!q.empty()){
        int X = q.front();
        q.pop();
        if(q.size()==0)break;
        int Y = q.front();
        if(p[X].size()==p[Y].size()){
            q.pop();
            merge(p[X],p[Y]);
            q.push(X);
        }else{
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    rep(i,n){
        if((int)p[i+1].size()!=0&&i!=0){
            pq.push({p[i+1].size(),i+1});
            // cerr << i+1 << " " << p[i].size() << end;
        }
    }
    while(pq.size() >= 2){
        
        auto xx = pq.top();
        pq.pop();
        int x = xx.second;
        auto yy = pq.top();
        int y = yy.second;
        // cerr << x << " " << y  << endl;
        while(p[x].size()==p[y].size()){
            // cerr <<"test" <<  x << " " << y << endl;
            pq.pop();
            merge(p[x],p[y]);
            if(pq.empty())break;
            yy = pq.top();
            y = yy.second;
        }
        if(pq.empty())break;
        merge(p[x],p[1]);
        pq.push({p[x].size(),x});
    }
    cout << res.size() << "\n";
    for(auto x:res){
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}