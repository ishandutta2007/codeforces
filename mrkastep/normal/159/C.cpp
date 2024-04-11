#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

string s;
int t[26][1000000];

void build(int v,int l,int r){
    int m=(l+r)/2,i;
    char c;
    if(l==r){
        t[s[l]-'a'][v]=1;
        return;
    }
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    for(i=0;i<26;i++){
        t[i][v]=t[i][2*v]+t[i][2*v+1];
    }
}

void mod(int v,int l,int r,int c,int n){
    int m=(l+r)/2;
    t[c][v]--;
    if(l==r) return;
    if(n>t[c][2*v]) mod(2*v+1,m+1,r,c,n-t[c][2*v]);
    else mod(2*v,l,m,c,n);
}

void out(int v,int l,int r){
    int i,m=(l+r)/2;
    if(l==r){
        For(i,26){
            if(t[i][v]==1) printf("%c",'a'+(char)i);
        }
        return;
    }
    out(2*v,l,m);
    out(2*v+1,m+1,r);
}

void solve(int k){
    int i,m,a;
    char c[1111],x;
    gets(c);
    gets(c);
    For(i,k) s+=c;
    build(1,0,s.length()-1);
    scanf("%d",&m);
    For(i,m){
        scanf("%d %c",&a,&x);
        mod(1,0,s.length()-1,x-'a',a);
    }
    out(1,0,s.length()-1);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}