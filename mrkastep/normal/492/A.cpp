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
    int i=0,s=0;
    while(s<=n){
        i++;
        s+=i*(i+1)/2;
    }
    printf("%d\n",i-1);
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