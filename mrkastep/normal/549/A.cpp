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
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

void solve(int n){
    int m;
    char c[111][111];
    scanf("%d",&m);
    gets(c[0]);
    For(i,n){
        gets(c[i]);
    }
    int ans=0;
    string s;
    For(i,n-1){
        For(j,m-1){
            s="";
            s.pb(c[i][j]);
            s.pb(c[i+1][j]);
            s.pb(c[i][j+1]);
            s.pb(c[i+1][j+1]);
            sort(all(s));
            if(s=="acef"){
                ans++;
            }
        }
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
    char c[111111];
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
    }






    return 0;
}