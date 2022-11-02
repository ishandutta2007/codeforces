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
    vector<string> seq;
    ll x,y,cx=0,cy=0;
    int i,a;
    scanf("%I64d%I64d",&x,&y);
    while(cx<x&&cy<y){
        if((cx+1)*y<(cy+1)*x){
            seq.pb("Vanya");
            cx++;
        }
        if((cx+1)*y>(cy+1)*x){
            seq.pb("Vova");
            cy++;
        }
        if((cx+1)*y==(cy+1)*x){
            seq.pb("Both");
            seq.pb("Both");
            cx++;
            cy++;
        }
    }
    For(i,n){
        scanf("%d",&a);
        printf("%s\n",seq[(a-1)%(x+y)].c_str());
    }

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