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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>p(n);
    vector<ll>c(n);
    vector<int>cnt(m);
    vector<vector<ll> > v(m);
    vector<vector<ll> > s(m,vector<ll>(n+1));
    vector<pair<ll,int> > a;
    rep(i,n){
        cin >> p[i] >> c[i];
        p[i]--;
        cnt[p[i]]++;
        v[p[i]].PB(c[i]);
        if(p[i]!=0)a.PB(MP(c[i],p[i]));
    }
    sort(a.begin(),a.end());
    rep(i,m){
        sort(v[i].begin(),v[i].end());
    }
    rep(i,m){
        rep(j,v[i].size()){
            s[i][j+1] = s[i][j] + v[i][j];
        }
    }
    ll ans = 1LL<<60;
    for(int i=1;i<=n;i++){
        int sm = v[0].size();
        ll tmp = 0;
        for(int j=1;j<m;j++){
            if(cnt[j]>=i){
                sm += cnt[j]-i+1;
                tmp += s[j][cnt[j]-i+1];
            }
        }
        if(sm>=i){
            ans = min(ans,tmp);
            continue;
        }
        vector<int> cnt2 = cnt;
        for(auto x:a){
            if(cnt2[x.second]>=i){
                cnt2[x.second]--;
            }else{
                sm++;
                tmp += x.first;
            }
            if(sm>=i)break;
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}