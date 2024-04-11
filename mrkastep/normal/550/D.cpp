#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
//#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
//const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;





void solve(int n){
    if(n%2==0){
        printf("NO");
        return;
    }
    if(n==1){
        printf("YES\n2 1\n1 2");
        return;
    }
    vector<pair<int,int>> e;
    For(i,4){
        e.pb(mp(i%4+1,(i+1)%4+1));
        e.pb(mp(i%4+1+n+2,(i+1)%4+1+n+2));
        if(i%2==0) e.pb(mp(5,i%4+1));
        if(i%2==0) e.pb(mp(5+n+2,i%4+1+n+2));
    }
    e.pb(mp(2,4));
    e.pb(mp(2+n+2,4+n+2));
    e.pb(mp(5,5+n+2));
    for(int i=3;i<n;i+=2){
        FOR(j,1,i+3){
            e.pb(mp(i+3,j));
            e.pb(mp(i+4,j));
            e.pb(mp(i+3+n+2,j+n+2));
            e.pb(mp(i+4+n+2,j+n+2));
        }
    }
    sort(all(e));
    printf("YES\n%d %d\n",2*n+4,e.size());
    For(i,e.size()){
        printf("%d %d\n",e[i].x,e[i].y);
    }




}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[111111];
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
        printf("\n");
    }






    return 0;
}