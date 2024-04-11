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

vector<int> a;

int l,r,c;

int check(int n){
    int s=0,mn=INF,mx=-INF;
    For(i,a.size()){
        if((1<<i)&n){
            s+=a[i];
            mn=min(a[i],mn);
            mx=max(mx,a[i]);
        }
    }
    return (int)(s>=l&&s<=r&&mx-mn>=c);
}





void solve(int n){
    int b;
    scanf("%d%d%d",&l,&r,&c);
    For(i,n){
        scanf("%d",&b);
        a.pb(b);
    }
    int ans=0;
    For(i,(1<<n)){
        ans+=check(i);
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
        printf("\n");
    }






    return 0;
}