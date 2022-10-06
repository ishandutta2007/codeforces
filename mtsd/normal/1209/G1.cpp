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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> l(200001,inf),r(200001,-inf);
    rep(i,n){
        l[a[i]] = min(l[a[i]],i);
        r[a[i]] = max(r[a[i]],i);
    }
    vector<int>p;
    p.push_back(-1);
    int id =0;
    rep(i,n){
        if(r[a[i]]==id&&id==i){
            p.push_back(i);
        }else{
            id = max(id,r[a[i]]);
        }
    }
    int sm = 0;
    rep(i,p.size()-1){
        int left = p[i]+1;
        int right = p[i+1];
        //cerr <<left << " " << right << endl;
        map<int,int>mp;
        for(int j=left;j<=right;j++){
            mp[a[j]]++;
        }
        int len = right-left+1;
        int ma = 0;
        for(auto x:mp){
            ma = max(ma,x.second);
        }
        sm += len-ma;
    }
    cout << sm << endl;
    return 0;
}