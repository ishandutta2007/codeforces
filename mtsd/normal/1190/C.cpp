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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ma = -1;
    int mi = n;
    bool flag = 0;
    bool fflag = 0;
    bool ffflag = 0;
    rep(i,n){
        if(s[i]=='0'){
            ma = max(ma,i);
            mi = min(mi,i);
        }
    }

    //cerr << ma-mi << endl;
    if(ma-mi<=k-1){
        flag = 1;
    }
    if(ma-mi==k&&mi<=k-1&&ma>=n-k){
        fflag = 1;
    }
    ma = -1;
    mi = n;
    rep(i,n){
        if(s[i]=='1'){
            ma = max(ma,i);
            mi = min(mi,i);
        }
    }
    if(ma-mi<=k-1){
        flag = 1;
    }
    //cerr << ma-mi << endl;
    if(ma-mi==k&&mi<=k-1&&ma>=n-k){
        ffflag = 1;
    }
    if(flag){
        cout << "tokitsukaze" << endl;
        return 0;
    }
    if(fflag&ffflag){
        cout << "quailty" << endl;
    }else{
        cout << "once again" << endl;
    }
    return 0;
}