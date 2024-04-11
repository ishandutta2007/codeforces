#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

double min(double x,double y){
    return x<y?x:y;
}


void solve(){
    int i,t;
    std::map<char,int> m;
    char x,s[30]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'},c[111];
    std::string g;
    For(i,30) m[s[i]]=i;
    x=getchar();
    if(x=='R') t=-1;
    else t=1;
    getchar();
    gets(c);
    g=c;
    For(i,g.length()) g[i]=s[m[g[i]]+t];
    printf("%s",g.c_str());
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
//    while(scanf("%d",&n)!=EOF){
        solve();
//    }
    return 0;
}