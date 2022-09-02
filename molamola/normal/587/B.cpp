#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int n, k;
ll L;
int a[1000010], b[1000010];
vector <vector<int> > v;
const ll MOD = 1e9 + 7;

void solve(int tc) {
    scanf("%d%lld%d",&n,&L,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i), b[i] = a[i];
    sort(b, b+n);
    v.resize(k);
    for(int i=0;i<k;i++)v[i].resize(n);
    for(int i=0;i<n;i++){
        if(i == n-1 || b[i] != b[i+1])v[0][i] = 1;
        else v[0][i] = 0;
    }
    for(int i=1;i<k;i++){
        ll sum = 0;
        for(int j=0, prev=0;j<n;j++){
            if(j == n-1 || b[j] != b[j+1]){
                sum += (ll)(j - prev + 1) * v[i-1][j];
                sum %= MOD;
                v[i][j] = (int)sum;
                prev = j+1;
            }
        }
    }
    /*
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++)printf("%d ",v[i][j]); puts("");
    }
     */
    ll ans = 0;
    ll re = L / n;
    for(int i=0;i<k && i<re;i++){
        for(int j=0, prev=0;j<n;j++){
            if(j == n-1 || b[j] != b[j+1]){
                ans += ((re - i) * (ll)(j - prev + 1) % MOD) * v[i][j];
                ans %= MOD;
                prev = j+1;
            }
        }
    }
    
    for(ll i=0;i<L - re * n;i++){
        int va = (int)(upper_bound(b, b+n, a[i]) - b);
        --va;
        for(int j=0;j<k && j<=re;j++){
            ans += v[j][va];
            ans %= MOD;
        }
    }
    
    printf("%lld",ans);
}

int main(){
    int Tc = 1;// scanf("%d",&Tc);
    for(int i=1;i<=Tc;i++){
        solve(i);
    }
    return 0;
}