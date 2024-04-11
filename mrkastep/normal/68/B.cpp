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

int a[10100],n,k;

bool check(double c){
    double s1=0,s2=0;
    int i;
    For(i,n){
        if(a[i]>c){
            s1+=a[i]-c;
        }
        else{
            s2-=a[i]-c;
        }
    }
    return s2/(100-k)*100<=s1;
}




void solve(){
    int i;
    double l=0,r=0;
    scanf("%d",&k);
    For(i,n){
        scanf("%d",&a[i]);
        r=max(r,(double)a[i]);
    }
    while(r-l>eps){
        double c=(l+r)/2;
        if(check(c)) l=c;
        else r=c;
    }
    printf("%.9lf",l);



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
    while(scanf("%d",&n)==1) solve();

    return 0;
}