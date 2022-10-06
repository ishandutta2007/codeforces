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
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];
    int q;
    cin >> q;
    rep(zz,q){
        int s;
        cin >> s;
        s--;
        string t;
        t += a[s%n];
        t += b[s%m];
        cout << t << "\n";
    }
    return 0;
}