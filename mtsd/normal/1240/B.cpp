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
    int q;
    cin >> q;
    rep(zz,q){
        int n;
        cin >> n;
        vector<int>a(n+1);
        vector<int>b(n+1);
        rep(i,n){
            cin >> a[i];
            b[a[i]] = 1;
        }
        vector<int>c(n+1,-1);
        int x = 0;
        rep(i,n+1){
            if(b[i]==1){
                c[i] = x;
                x++;
            }
        }
        rep(i,n){
            a[i] = c[a[i]];
        }
        int m = x;
        vector<int>l(m,inf);
        vector<int>r(m,-inf);
        rep(i,n){
            l[a[i]] = min(l[a[i]],i);
            r[a[i]] = max(r[a[i]],i);
        }
        // rep(i,m){
        //     cerr << l[i] << " " << r[i] << endl;
        // }
        int mx = 0;
        int cnt = 0;
        rep(i,m){
            if(i==0){
                cnt++;
            }else{
                if(r[i-1]<l[i]){
                    cnt++;
                }else{
                    mx = max(mx,cnt);
                    cnt = 1;
                }
            }
        }
        mx = max(mx,cnt);
        cout << m-mx << "\n";
    }   
    return 0;
}