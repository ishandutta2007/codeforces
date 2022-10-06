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
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int>res(n);
    vector<bool>flag(n);
    vector<bool>m(n);
    int sm = 0;
    rep(i,n){
        if(a[i]%2==0){
            res[i] = a[i]/2;
            sm += a[i]/2;
        }else{
            flag[i] = 1;
            
            if(a[i]<0){
                
                res[i] = a[i]/2-1;
                sm += a[i]/2 - 1;
            }else{
                res[i] = a[i]/2;
                sm += a[i]/2;
            
            }
        }
    }
    rep(i,n){
        if(!flag[i]){
            cout << res[i] << "\n";
        }else if(sm!=0){
            res[i]++;
            sm++;
            cout << res[i] << "\n";
        }else{
            cout << res[i] << "\n";
        }
    }
    // int s = 0;
    // rep(i,n){
    //     s += res[i];
    // }
    // cout << s << endl;
    return 0;
}