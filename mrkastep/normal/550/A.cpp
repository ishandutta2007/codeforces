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

void solve(string &s){
    vector<int> a[2];
    int n=s.size()-1;
    For(i,n){
        if(s[i]=='A'&&s[i+1]=='B') a[0].pb(i);
        if(s[i]=='B'&&s[i+1]=='A') a[1].pb(i);
    }
    if(a[0].size()*a[1].size()){
        if(abs(a[0][0]-a[1].back())>1||abs(a[0].back()-a[1][0])>1){
            printf("YES");
            return;
        }
    }
    printf("NO");








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
    while(gets(c)){
        solve(s=c);
        printf("\n");
    }






    return 0;
}