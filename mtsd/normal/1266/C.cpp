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
    ll n,m;
    cin >> n >> m;
    if(n==1&&m==1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n),b(m);
    if(n<=m){
        rep(i,n){
            a[i] = i+1;
        }
        rep(i,m){
            b[i] = i+n+1;
        }
    }else{
        rep(i,m){
            b[i] = i+1;
        }
        rep(i,n){
            a[i] = i+m+1;
        }
    }
    rep(i,n){
        rep(j,m){
            cout << a[i]*b[j];
            if(j!=m-1){
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}