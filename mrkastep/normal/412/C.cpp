#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

char c[100001];

void solve(int n){
    int i,j;
    std::vector<std::string> a;
    std::string s;
    gets(c);
    char t;
    For(i,n){
        gets(c);
        s=c;
        a.push_back(s);
    }
    s="";
    For(i,a[0].length()){
        t='*';
        For(j,a.size()){
            if(a[j][i]!='?'){
                if(t!=a[j][i]){
                    if(t!='*') t='?';
                    else t=a[j][i];
                }
            }
        }
        if(t=='*') t='a';
        s+=t;
    }
    printf("%s",s.c_str());
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}