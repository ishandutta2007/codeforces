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

char c1[1001000];

void solve(string s){
    string t;
    int i,p,p1=INF,p2=0;
    gets(c1);
    t=c1;
    i=0;
    p=0;
    while(i<t.size()&&p<s.size()){
        if(t[i]==s[p]){
            p++;
        }
        i++;
    }
    if(p==s.size()) p1=i-1;
    i=t.size()-1;
    p=s.size()-1;
    while(i>=0&&p>=0){
        if(t[i]==s[p]){
            p--;
        }
        i--;
    }
    if(p==-1) p2=i+1;
    if(p2-p1<0){
        printf("0");
    }
    else{
        printf("%d",p2-p1);
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
    char c[200200];
    string s;
    while(gets(c)) solve(s=c);

    return 0;
}