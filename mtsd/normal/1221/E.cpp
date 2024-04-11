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
    rep(tt,q){
        int a,b;
        string s;
        cin >> a >> b >> s;
        int n = s.size();
        int c = 0;
        vector<int> v;
        rep(i,n){
            if(s[i]=='.'){
                c++;
            }else{
                if(c!=0){
                    v.push_back(c);
                    c = 0;
                }
            }
        }
        if(c!=0){
            v.push_back(c);
        }
        if(v.size()==0){
            cout << "NO\n";
            continue;
        }
        sort(v.begin(),v.end(),greater<int>());
        n = v.size();
        int cnt = 0;
        bool bob = false;
        for(int i=1;i<n;i++){
            if(v[i]>=2*b){
                bob = true;
            }
            if(v[i]<a&&v[i]>=b){
                bob = true;
            }
            if(v[i]>=b&&v[i]>=a){
                cnt++;
            }
        }
        bool flag[3] = {};
    
        for(int c1=0;c1<v[0];c1++){
            if(c1+a>v[0])break;
            int c2 = v[0]-c1-a;
            if(c1>=2*b||c2>=2*b)continue;
            if(c1>=b&&c1<a){
                continue;
            }
            if(c2>=b&&c2<a){
                continue;
            }
            int c = 0;
            if(c1>=b){
                c++;
            }
            if(c2>=b){
                c++;
            }
            flag[c] = true;
        }
        
        if(bob){
            cout <<"NO\n";
            continue;
        }
        if(cnt%2==0&&(flag[0]||flag[2])){
            cout << "YES\n";
            continue;
        }
        if(cnt%2==1&&flag[1]){
            cout <<"YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}