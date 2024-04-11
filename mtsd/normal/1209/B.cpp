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
    string s;
    vector<int> a(n),b(n);
    cin >> s;
    rep(i,n) cin >> a[i] >> b[i];
    int mx = 0;
    rep(i,10000){
        int c = 0;
        rep(j,n){
            bool p=0;
            if(i<b[j]){
                p = 0;
            }else{
                if((i-b[j])/a[j]%2==0){
                    p = 1;
                }else{
                    p = 0;
                }
            }
            if(p){
                if(s[j]=='0'){
                    c++;
                }
            }else{
                if(s[j]=='1'){
                    c++;
                }
            }
        }
        mx = max(mx,c);
    }   
    cout << mx << endl;
    return 0;
}