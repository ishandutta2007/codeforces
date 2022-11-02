#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

int f(int n){
    int c=1,i;
    For(i,n) c*=i+1;
    return c;
}

int cnk(int n,int k){
    return f(n)/(f(k)*f(n-k));
}

int mod(int x){
    return x<0?-x:x;
}

void solve(){
    int i,pos=0,t=0,n=0;
    double ans=1;
    char c[15];
    gets(c);
    For(i,strlen(c)){
        if(c[i]=='+') pos++;
        else pos--;
    }
    gets(c);
    For(i,strlen(c)){
        if(c[i]=='+') t++;
        if(c[i]=='-') t--;
        if(c[i]=='?') n++;
    }
    For(i,n) ans*=0.5;
    if(mod(t-pos)>n){
        printf("0");
        return;
    }
    ans*=cnk(n,(n-mod(t-pos))/2);
    printf("%.10lf",ans);

}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
//    while(scanf("%d",&n)!=EOF){
        solve();
//    }
    return 0;
}