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


int main(){
    ll r;
    cin >> r;
    ll y = -1;
    ll x = -1;
    for(ll i=1;i<=1000000;i++){
        if(r-i-1-i*i>0&&(r-i-1-i*i)%(2*i)==0){
            x =i;
            y = (r-i-1-i*i)/(2*i);
            break;
        }
    }
    if(y==-1){
        cout << "NO" << endl;
    }else{
        cout << x << " " << y << endl;
    }
    return 0;
}