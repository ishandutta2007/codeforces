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



void solve(){
    vector<int> f,s;
    int i,n,a;
    ll s1=0,s2=0;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a);
        if(a>0){
            f.pb(a);
            s1+=a;
        }
        else{
            s.pb(-a);
            s2-=a;
        }
    }
    if(s1>s2){
        printf("first");
        return;
    }
    if(s2>s1){
        printf("second");
        return;
    }
    if(f>s){
        printf("first");
        return;
    }
    if(f<s){
        printf("second");
        return;
    }
    if(a>0){
        printf("first");
        return;
    }
    printf("second");



}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    
    solve();
    
    return 0;
}