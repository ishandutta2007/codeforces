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
const int mod=1e5+3;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

char c[200200],cc[5];

void solve(){
    int n,m;
    char a,b,d[26],e[26];
    For(i,26) d[i]='a'+i;
    scanf("%d%d\n",&n,&m);
    gets(c);
    For(i,m){
        gets(cc);
        swap(d[cc[0]-'a'],d[cc[2]-'a']);
    }
    For(i,26){
        e[d[i]-'a']=i+'a';
    }
    For(i,n){
        printf("%c",e[c[i]-'a']);
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