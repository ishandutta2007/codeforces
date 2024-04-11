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
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n){
            cin >> a[i];
        }
        int k = n/2-1;
        while(k>=0){
            if(a[k]==a[n/2]){
                k--;
            }else{
                break;
            }
        }
        int g=0,s=0,b=0;
        int id = n;
        rep(i,n){
            if(a[i]==a[0]){
                g++;
            }else{
                id = i;
                break;
            }
        }
        int pre = -1;
        bool f = 1;
        while(id<=k){
            if(g>=s){
                s++;
                pre = a[id];
                id++;
            }else{
                if(f){
                    if(pre==a[id]){
                        s++;
                    }else{
                        b++;
                        f = 0;
                    }
                }else{
                    b++;
                }
                id++;
            }
        }
        if(g<s&&g<b&&2*(g+s+b)<=n){
            cout << g << " " << s << " " << b << "\n";
        }else{
            cout << "0 0 0\n";
        }
    }
    return 0;
}