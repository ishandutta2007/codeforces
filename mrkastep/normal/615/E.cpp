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
#include <unordered_map>
#include <stack>
#include <set>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define x first
#define y second

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;
//typedef pair<double,double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;



void solve(){
    ll n,c,l,r;
    scanf("%I64d",&n);
    l=0,r=1e9;
    while(r-l>1){
        c=(l+r)/2;
        if(3*c*(c+1)<=n) l=c;
        else r=c;
    }
    c=l;
    n-=3*c*(c+1);
    ll a,b;
    a=c*2;
    b=0;
    if(n==0){
        printf("%I64d %I64d",a,b);
        return;
    }
    a++;
    b+=2;
    n--;
    if(n>c){
        a-=(c);
        b+=2*(c);
        n-=c;
    }
    else{
        a-=n;
        b+=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }
    if(n>c+1){
        a-=2*(c+1);
        n-=c+1;
    }
    else{
        a-=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }
    if(n>c+1){
        a-=(c+1);
        b-=2*(c+1);
        n-=c+1;
    }
    else{
        a-=n;
        b-=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }
    if(n>c+1){
        a+=(c+1);
        b-=2*(c+1);
        n-=c+1;
    }
    else{
        a+=n;
        b-=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }
    if(n>c+1){
        a+=2*(c+1);
        n-=c+1;
    }
    else{
        a+=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }
    if(n>c+1){
        a+=(c+1);
        b+=2*(c+1);
        n-=c+1;
    }
    else{
        a+=n;
        b+=2*n;
        printf("%I64d %I64d",a,b);
        return;
    }

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //#else
    //  freopen("a.in","rt",stdin);
    //  freopen("a.out","wt",stdout);
#endif
    solve();
    return 0;
}