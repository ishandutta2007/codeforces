#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int n;

bool read(){
    return scanf("%d",&n)==1;
}

void solve(){
    int l;
    scanf("%d",&l);
    int i,a[1111],ans=0;
    For(i,n){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    For(i,n-1) ans=max(ans,a[i+1]-a[i]);
    ans=max(ans,2*a[0]);
    ans=max(ans,2*(l-a[n-1]));
    printf("%.10lf",(double)ans/2);

}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    
    while(read()) solve();
    
    return 0;
}