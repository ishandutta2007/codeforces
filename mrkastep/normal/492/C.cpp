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
    int r,i;
    ll ans=0,av=0,avg;
    pair<int,int> a[111111];
    scanf("%d%I64d",&r,&avg);
    For(i,n){
        scanf("%d%d",&a[i].second,&a[i].first);
        av+=a[i].second;
    }
    sort(a,a+n);
    i=0;
    avg*=n;
    while(av<avg){
        if(av+(r-a[i].second)<avg){
            ans+=(ll)(r-a[i].second)*a[i].first;
            av+=r-a[i].second;
        }
        else{
            ans+=(avg-av)*a[i].first;
            av=avg;
        }
        i++;
    }
    printf("%I64d\n",ans);

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