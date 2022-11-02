#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const ll LONGINF=4e18;
const double eps=1e-9;

template<typename T>void swap(T *x1,T *x2){
    T t;
    t=*x1;
    *x1=*x2;
    *x2=t;
}

int a[100100],ans[100100];

void solve(int n){
    int i,k,l,r;
    vector<int> an;
    For(i,n){
        scanf("%d",&a[n-1-i]);
    }
    For(i,n){
        if(i==0) ans[i]=a[i];
        else ans[i]=min(ans[i-1],a[i]);
    }
    For(i,n){
        if(i==0){
            an.pb(-1);
            continue;
        }
        l=0;
        r=i-1;
        while(r-l>1){
            int c=(l+r)/2;
            if(ans[c]>=a[i]){
                l=c;
            }
            else r=c;
        }
        if(ans[r]>=a[i]){
            an.pb(-1);
            continue;
        }
        if(ans[l]<a[i]){
            an.pb(i-l-1);
            continue;
        }
        an.pb(i-r-1);
    }
    For(i,n){
        printf("%d ",an[n-i-1]);
    }



#ifndef ONLINE_JUDGE
    printf("\n\nTime in ms: %.0lf",(double)clock() / CLOCKS_PER_SEC * 1000);
#endif
}


int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}