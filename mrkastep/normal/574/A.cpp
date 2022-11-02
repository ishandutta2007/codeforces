#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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

char c[333333];

void solve(int n){
    int a[111];
    For(i,n){
        scanf("%d",&a[i]);
    }
    int ans=0;
    while(true){
        int mx=0,t=-1;
        FOR(i,1,n){
            if(a[i]>mx) mx=a[i],t=i;
        }
        if(mx>=a[0]) a[0]++,a[t]--,ans++;
        else break;
    }
    printf("%d",ans);
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}