#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll a[1000010];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=1;i<n;i++){
        if(s[i]=='v'&&s[i-1]=='v'){
            a[i]++;
        }
    }
    for(int i=1;i<n;i++){
        a[i] += a[i-1];
    }
    ll res = 0;
    for(int i=1;i<n;i++){
        if(s[i]=='o'){
            res += (a[n-1]-a[i])*a[i-1]; 
        }
    }
    cout << res << endl;
    return 0;
}