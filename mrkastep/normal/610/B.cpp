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

int a[200200];

void solve(){
    int n,mn=INF,mni,st=0,f=0,l=0,t=0;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a[i]);
        if(a[i]<mn){
            mn=a[i];
            mni=i;
        }
    }
    For(i,n){
        if(a[i]==mn){
            if(i==t){
                st=t;
            }
            l=max(l,t);
            t=0;
        }
        else t++;
    }
    printf("%I64d",(ll)n*mn+max(l,st+t));
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