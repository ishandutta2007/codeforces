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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> p = a;
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int dd = 0;
    map<int,int> mp;
    vector<int> unzip;
    rep(i,p.size()){
        mp[p[i]] = i;
        unzip.push_back(p[i]);
        dd++;
    }

    vector<int> b= a;
    sort(b.begin(),b.end(),greater<int>());
    vector<int>s(dd);
    for(int i=0;i<n;i++){
        b[i] = mp[b[i]];
        a[i] = mp[a[i]];
        s[b[i]]++;
    }
    for(int i=dd-2;i>=0;i--){
        s[i] += s[i+1];
    }
    int m;
    cin >> m;
    rep(i,m){
        int k,pos;
        cin >> k >> pos;
        int tar = b[k-1];
        int c = 0;
        rep(i,k){
            if(b[i]==tar){
                c++;
            }
        }
        vector<int> res;
        rep(i,n){
            if(a[i]>tar){
                res.push_back(a[i]);
            }else if(a[i]==tar){
                if(c>0){
                    res.push_back(a[i]);
                    c--;
                }
            }
        }
        cout << unzip[res[pos-1]] << "\n";
    }
    return 0;
}