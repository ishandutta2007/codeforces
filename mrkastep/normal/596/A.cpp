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
#define all(v) (v).begin(),(v).end()

typedef long long int ll;

const int INF=1e9;
const int mod=366239;
const long long int LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;






void solve(){
    int n;
    pair<int,int> a[4];
    scanf("%d",&n);
    For(i,n){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    if(n==1){
        printf("-1");
    }
    if(n==2){
        if(a[0].x-a[1].x!=0&&a[0].y-a[1].y!=0){
            printf("%d",abs((a[0].x-a[1].x)*(a[0].y-a[1].y)));
        }
        else{
            printf("-1");
        }
    }
    if(n==3){
        printf("%d",(abs(a[0].x-a[1].x)+abs(a[0].x-a[2].x)+abs(a[1].x-a[2].x))/2*(abs(a[0].y-a[1].y)+abs(a[0].y-a[2].y)+abs(a[1].y-a[2].y))/2);
    }
    sort(a,a+n);
    if(n==4){
        printf("%d",abs(a[0].x-a[3].x)*abs(a[0].y-a[1].y));

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