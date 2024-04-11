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
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll,int> mp;
    ll sm  = 0;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
        sm += a[i];
    }
    bool flag = 0;
    int aaa = 0;
    for(auto x:mp){
        if(x.second>2){
            flag = 1;
        }
        if(x.second==2){
            aaa++;
            if(x.first ==0){
                flag = 1;
            }
            if(mp.find(x.first-1)!=mp.end()){
                flag = 1;
            }
        }
        if(aaa>=2){
            flag = 1;
        }
    }
    if(flag){
        cout << "cslnb" << endl;
        return 0;
    }
    ll p = 0;
    for(int i=0;i<n;i++){
        p +=i;
    }
    if((sm-p)%2==0){
        cout << "cslnb" << endl;
    }else{
        cout << "sjfnb" << endl;
    }
    return 0;
}