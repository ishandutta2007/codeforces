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

typedef pair<double,double> point;
typedef long long int ll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

ll d[4040][4040];

void solve(int n){
    int a,b;
    bool g=true;
    scanf("%d",&b);
    while(b%2==0) b/=2;
    while(b%3==0) b/=3;
    For(i,n-1){
        scanf("%d",&a);
        while(a%2==0) a/=2;
        while(a%3==0) a/=3;
        if(g&&a!=b){
            printf("No");
            g=false;
        }
    }
    if(g) printf("Yes");


#ifdef _DEBUG
    printf("\n\nTime: %d\n\n",(ll)1000*clock()/CLOCKS_PER_SEC);
#endif
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    scanf("%d",&n); solve(n);
    return 0;
}