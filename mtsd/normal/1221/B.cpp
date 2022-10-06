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
    vector<string> v(n);
    rep(i,n){
        string s;
        if(i%2==0){
            rep(j,n){
                if(j%2==0){
                    s.push_back('W');
                }else{
                    s.push_back('B');
                }
            }
        }else{
            rep(j,n){
                if(j%2==0){
                    s.push_back('B');
                }else{
                    s.push_back('W');
                }
            }
        }
        v[i] = s;
    }
    rep(i,n){
        cout << v[i] << endl;
    }
    return 0;
}