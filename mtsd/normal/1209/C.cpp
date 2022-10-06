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
        string s;
        cin >> n >> s;
        int sss = s[0]-'0';
        string res;
        vector<int> p(n);
        bool ok = false;
        rep(zzz,10){
            rep(i,n)p[i] = 0;
            int a = sss;
            int b = zzz;
            int ccc = max(a,b);
            if(a>b){
                swap(a,b);
            }
            bool flag = 0;
            rep(i,n){
                int k = s[i]-'0';
                if(k<a){
                    flag = 1;
                    break;
                }
                if(k>=b){
                    p[i] = 2;
                    b = k;
                }else{
                    p[i] = 1;
                    a = k;
                }
            }
            if(flag)continue;
            if(a<=ccc){
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "-\n";
        }else{
            rep(i,n){
                res.push_back('0'+p[i]);
            }
            cout << res <<"\n";
        }
    }
    return 0;
}