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
const int mod=1e9;
const ll LONGINF=4e18;
const double eps=1e-5;
const double PI=3.1415926535897932384626433832795;

int a[200200],b[200200];

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    For(i,n) scanf("%d",&a[i]);
    For(i,m) scanf("%d",&b[i]);
    sort(a,a+n);
    For(i,m){
        int l=-1,r=n;
        while(r-l>1){
            int c=(l+r)/2;
            if(a[c]>b[i]) r=c;
            else l=c;
        }
        printf("%d ",r);
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