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

void swap(int &a,int &b){
    int t;
    t=a;
    a=b;
    b=t;
}

void solve(int a){
    int b,c,d,e,f;
    scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
    if(c<=a&&d<=b&&(a-c>=e&&f<=b||b-d>=f&&e<=a)){
        printf("YES");
        return;
    }
    swap(e,f);
    if(c<=a&&d<=b&&(a-c>=e&&f<=b||b-d>=f&&e<=a)){
        printf("YES");
        return;
    }
    swap(e,f);
    swap(c,d);
    if(c<=a&&d<=b&&(a-c>=e&&f<=b||b-d>=f&&e<=a)){
        printf("YES");
        return;
    }
    swap(e,f);
    if(c<=a&&d<=b&&(a-c>=e&&f<=b||b-d>=f&&e<=a)){
        printf("YES");
        return;
    }
    printf("NO");







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
    char c[111];
    string s;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}