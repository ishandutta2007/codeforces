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
#include <cmath>
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define point complex<double>
#define x first
#define y second

typedef long long int ll;
typedef vector<ll> lll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;


vector<string> v;

void turn(string &s){
    For(i,s.size()){
        if(s[i]=='*') s[i]='+';
        else s[i]='*';
    }
}

void build(int n){
    if(n==0){
        return;
    }
    build(n-1);
    int s=v.size();
    For(i,s){
        v.pb(v[i]);
    }
    For(i,s) turn(v[i+s]);
    for(int i=s*2-1;i>=0;i--){
        v[i]+=v[i%s];
    }
}

void solve(){
    int n;
    scanf("%d",&n);
    string s="*";
    v.pb(s);
    build(n);
    For(i,v.size()){
        printf("%s\n",v[i].c_str());
    }

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