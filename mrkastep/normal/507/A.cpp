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
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

pair<int,int> a[111];

void solve(){
    int s=0,n,k,ans=0;
    scanf("%d%d",&n,&k);
    For(i,n){
        scanf("%d",&a[i].x);
        a[i].y=i+1;
    }
    a[n].x=INF;
    sort(a,a+n);
    while(s+a[ans].x<=k){
        s+=a[ans].x;
        ans++;
    }
    printf("%d\n",ans);
    For(i,ans){
        printf("%d ",a[i].y);
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