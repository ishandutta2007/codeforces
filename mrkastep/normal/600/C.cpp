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

char c[200100];
int s[26];

void solve(){
    For(i,26) s[i]=0;
    gets(c);
    int n=strlen(c);
    vector<int> odd;
    For(i,n){
        s[c[i]-'a']++;
    }
    For(i,26) if(s[i]%2) odd.pb(i);
    For(i,odd.size()/2){
        s[odd[i]]++;
        s[odd[odd.size()-i-1]]--;
    }
    For(i,26) For(j,s[i]/2) printf("%c",i+'a');
    For(i,26) if(s[i]%2) printf("%c",i+'a');
    for(int i=25;i>=0;i--) For(j,s[i]/2) printf("%c",i+'a');
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