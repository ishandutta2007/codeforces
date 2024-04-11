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
    int n;
    cin >> n;
    vector<int>c(n+1);
    vector<int>r(n+1);
    rep(i,n){
        cin >> c[i+1];
    }
    rep(i,n){
        cin >> r[i+1];
    }
    vector<pair<int,pair<int,int> > > a;
    for(int i=1;i<=n;i++){
        int C,R;
        for(int j=1;j<=n;j++){
            if(c[j]==i){
                C = j;
            }
        }
        for(int j=1;j<=n;j++){
            if(r[j]==i){
                R = j;
            }
        }
        if(C==i&&R==i)continue;
        a.push_back(MP(i,MP(C,R)));
        swap(c[C],c[i]);swap(r[i],r[R]);
    }
    cout << a.size() << "\n";
    for(auto x:a){
        cout << x.second.first << " " <<  x.first << " " <<  x.first << " " << x.second.second  << "\n";
    }
    return 0;
}