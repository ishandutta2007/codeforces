#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

void solve(string s){
    char c[111];
    bool g=true;
    int i=s.length()-1;
    string t;
    gets(c);
    t=c;
    while(i>=0&&g){
        s[i]=s[i]+1;
        g=false;
        if(s[i]>'z'){
            s[i]-=26;
            g=true;
        }
        i--;
    }
    if(s<t){
        printf("%s",s.c_str());
    }
    else{
        printf("No such string");
    }





#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[1001];
    string s;
    while(gets(c)) solve(s=c);

    return 0;
}