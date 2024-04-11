
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e5+3;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int a[100100];

void solve(){
    int n,k=0,d=1;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a[i]);
    }
    For(i,n){
        if(a[i]==i) k++;
        else if(a[a[i]]==i) d=2;
    }
    if(k==n){
        printf("%d",k);
    }
    else{
        printf("%d",k+d);
    }


}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}