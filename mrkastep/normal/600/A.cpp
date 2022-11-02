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

bool check(char c){
    return c!=','&&c!=';'&&c!=EOF;
}

char C[100100];
int pos=0,n;

char get(){
    if(pos==n){
        pos++;
        return ',';
    }
    pos++;
    return C[pos-1];
}

string word(){
    string s;
    char c;
    while(check(c=get())) s+=c;
    return s;
}

bool num(string &s){
    if(s.empty()) return false;
    For(i,s.size()){
        if(s[i]>'9'||s[i]<'0') return false;
    }
    if(s.size()>1&&s[0]=='0') return false;
    return true;
}

void solve(){
    vector<string> a,b;
    gets(C);
    n=strlen(C);
    while(pos<n||pos==n&&!check(C[n-1])){
        string s=word();
        if(num(s)) a.pb(s);
        else b.pb(s);
    }
    if(a.empty()){
        puts("-");
    }
    else{
        printf("\"");
        For(i,a.size()){
            if(i>0) printf(",");
            printf("%s",a[i].c_str());
        }
        printf("\"\n");
    }
    if(b.empty()){
        puts("-");
    }
    else{
        printf("\"");
        For(i,b.size()){
            if(i>0) printf(",");
            printf("%s",b[i].c_str());
        }
        printf("\"");
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