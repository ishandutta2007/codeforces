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
    int n;
    cin >> n;
    vector<int>a(n),b(n);  
    rep(i,n){
        cin >> a[i];

        a[i]--;
    }
    rep(i,n){
        cin >> b[i];
        b[i]--;
    }
    vector<int>c(n);
    int sm = 0;
    vector<bool>flag(n);
    int id = 0;
    int ad = 0;
    while(id!=n){
        while(ad<n&&flag[a[ad]]){
            ad++;
        }
        if(ad==n)break;
        while(b[id]!=a[ad]){
            sm++;
            flag[b[id]] = true;
            id++;
        }
        flag[a[ad]] = true;
        id++;
        ad++;
    }
    cout << sm << endl;
    return 0;
}