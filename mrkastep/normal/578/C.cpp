#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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
int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int a[200200],l;
double tmp;

double check(double x){
    double mins=0,maxs=0,s=0,maxa=-1e11,mina=1e11;
    For(i,l){
        s+=a[i]-x;
        maxa=max(s-mins,maxa);
        mina=min(s-maxs,mina);
        mins=min(mins,s);
        maxs=max(maxs,s);
    }
    tmp=maxa;
    return maxa+mina;
}

void solve(int n){
    For(i,n) scanf("%d",&a[i]);
    double L=-20000,R=20000;
    l=n;
    double ans=0;
    while(R-L>eps){
        double c=(L+R)/2,d=check(c);
        if(d>0)
            L=c;
        else
            R=c;
    }
    check(R);
    printf("%.10lf",tmp);






}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}