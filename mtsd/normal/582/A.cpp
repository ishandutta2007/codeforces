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
template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a,T b)
{
    return  a / gcd(a,b) * b;
}

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    priority_queue<int>pq;
    rep(i,n*n){
        int a;
        cin >> a;
        pq.push(a);
        mp[a]++;
    }
    vector<int> res;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(mp[x]==0)continue; 
        res.push_back(x);
        int m = res.size();
        for(int i=0;i<m-1;i++){
            mp[gcd(res[i],x)] -= 2;
        }
        mp[x]--;
    }
    for(auto x:res){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}