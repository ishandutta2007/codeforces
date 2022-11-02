#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
 
using namespace std;
 
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ll long long int
 
 
const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
 
typedef pair<int,int> point;


char c[100100];

void solve(string &s){
    string t;
    gets(c);
    t=c;
    int d=0,n=s.size();
    For(i,n){
        if(s[i]!=t[i]){
            d++;
        }
    }
    if(d%2!=0){
        printf("impossible");
        return;
    }
    d/=2;
    int p=0;
    while(d>0){
        if(s[p]!=t[p]){
            t[p]=1-(t[p]-'0')+'0';
            d--;
        }
        p++;
    }
    printf("%s",t.c_str());





}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    ll a;
    int n;
    string s;
    while(gets(c)) solve(s=c);
    return 0;
}