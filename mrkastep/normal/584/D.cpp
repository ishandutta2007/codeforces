#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

bool prime(int a){
    if(a<2) return false;
    FOR(i,2,(int)sqrt((double)a)+1){
        if(a%i==0) return false;
    }
    return true;
}




void solve(){
    int n,tt;
    scanf("%d",&n);
    vector<int> t;
    tt=n;
    while(!prime(tt)){
        if(tt==n) tt--;
        tt--;
    }
    t.pb(tt);
    n-=tt;
    if(prime(n)){
        t.pb(n);
        n=0;    
    }
    if(n==0){
        printf("%d\n",t.size());
        For(i,t.size()) printf("%d ",t[i]);
        return;
    }
    FOR(i,2,n){
        if(prime(i)&&prime(n-i)){
            t.pb(i);
            t.pb(n-i);
            break;
        }
    }
    printf("%d\n",t.size());
    For(i,t.size()) printf("%d ",t[i]);

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}