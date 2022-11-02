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
#define all(v) (v).begin(),(v).end()


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

int ans=0;

void solve(string s){
    int i;
    For(i,s.size()){
        if(s[i]=='Q') ans+=9;
        if(s[i]=='q') ans-=9;
        if(s[i]=='R') ans+=5;
        if(s[i]=='r') ans-=5;
        if(s[i]=='B') ans+=3;
        if(s[i]=='b') ans-=3;
        if(s[i]=='N') ans+=3;
        if(s[i]=='n') ans-=3;
        if(s[i]=='P') ans++;
        if(s[i]=='p') ans--;
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
    if(ans>0){
        printf("White");
    }
    if(ans<0){
        printf("Black");
    }
    if(ans==0){
        printf("Draw");
    }
    return 0;
}