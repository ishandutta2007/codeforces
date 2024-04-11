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

int a[500500];

void solve(){
    int n;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a[i]);
    }
    vector<pair<int,int>> v;
    int l,s,t;
    FOR(i,1,n){
        l=0;
        vector<int> one;
        while(i<n&&a[i]==a[i-1]) i++;
        t=i;
        while(i<n&&a[i]!=a[i-1]) l++,i++;
        l--;
        v.pb(mp(t,l));
    }
    For(i,v.size()){
        if(v[i].y%2==1){
            For(j,v[i].y){
                a[v[i].x+j]=a[v[i].x-1];
            }
        }
        else{
            For(j,v[i].y/2){
                a[v[i].x+j]=a[v[i].x-1];
                a[v[i].x+v[i].y-j-1]=1-a[v[i].x-1];
            }
        }
    }
    int ans=0;
    For(i,v.size()){
        ans=max(ans,(v[i].y+1)/2);
    }
    printf("%d\n",ans);
    For(i,n){
        printf("%d ",a[i]);
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