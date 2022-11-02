#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    std::map<std::string,int> m;
    std::map<std::string,int>::iterator it;
    int i;
    char c[33];
    std::string s;
    gets(c);
    For(i,n){
        gets(c);
        s=c;
        if(m[s]!=0){
            printf("%s%d\n",s.c_str(),m[s]);
            m[s]++;
        }
        else{
            printf("OK\n");
            m[s]=1;
        }
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}