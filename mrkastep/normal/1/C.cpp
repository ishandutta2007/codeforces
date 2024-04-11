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
const int mod=1e9;
const ll LONGINF=4e18;
const double eps=1e-5;
const double PI=3.1415926535897932384626433832795;

typedef complex<double> point;

double md(double a,double b){
    return a-(int)(a/b)*b;
}

double gcd(double a,double b){
    while(a>eps&&b>eps){
        if(a>b) a=md(a,b);
        else b=md(b,a);
    }
    return max(a,b);
}

void solve(){
    point a,b,c,O;
    double X,Y;
    scanf("%lf%lf",&X,&Y);
    a.real(X);
    a.imag(Y);
    scanf("%lf%lf",&X,&Y);
    b.real(X);
    b.imag(Y);
    scanf("%lf%lf",&X,&Y);
    c.real(X);
    c.imag(Y);
    double A=norm(b-c),B=norm(c-a),C=norm(a-b);
    O=(a*(A*(B+C-A))+b*(B*(C+A-B))+c*(C*(A+B-C)))/((A*(B+C-A))+(B*(C+A-B))+(C*(A+B-C)));
    a-=O;
    b-=O;
    c-=O;
    A=arg(a);
    B=arg(b);
    C=arg(c);
    if(A<0) A+=2*PI;
    if(B<0) B+=2*PI;
    if(C<0) C+=2*PI;
    FOR(i,3,101){
        if(abs(sin(i*(A-B)/2))<eps&&abs(sin(i*(C-B)/2))<eps){
            printf("%.10lf",norm(a)*sin(2*PI/i)/2*i);
            return;
        }
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