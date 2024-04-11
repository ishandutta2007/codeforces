#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <complex>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long int ll;
typedef vector<ll> lll;

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

char c[100100];

void solve(){
    int n;
    vector<int> v;
    scanf("%d\n",&n);
    gets(c);
    v.pb(1);
    FOR(i,1,n){
        if(c[i]==c[i-1]) v.back()++;
        else v.pb(1);
    }
    int t=0;
    For(i,v.size()) t=max(t,v[i]);
    if(t>=3){
        printf("%d",v.size()+2);
        return;
    }
    if(t==1){
        printf("%d",n);
        return;
    }
    t=0;
    int tw=0;
    For(i,v.size()){
        if(v[i]==2) tw++;
    }
    if(tw==1){
        printf("%d",v.size()+1);
        return;
    }
    if(tw>2){
        printf("%d",v.size()+2);
        return;
    }
    printf("%d",v.size()+2);
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