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
    vector<int> v;
    map<int,int> m;
    int a;
    For(i,n){
        scanf("%d",&a);
        m[a]++;
        v.pb(a);
    }
    int s=1;
    for(auto it=m.rbegin();it!=m.rend();it++){
        s+=it->y;
        it->y=s-it->y;
    }
    For(i,n){
        printf("%d ",m[v[i]]);
    }




}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    char c[100100];
    while(scanf("%d",&n)==1){
        solve(n);
        printf("\n");
    }






    return 0;
}