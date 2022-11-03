#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;

int n;
bool f[N];

int main(){
    scanf("%d",&n);
    n++;
    rep(i,2,n){
        for(int j=i+i;j<=n;j+=i)
            f[j]=1;
    }
    if(n-1>2) puts("2");
    else puts("1");
    rep(i,2,n){
        if(f[i]) printf("2 ");
        else printf("1 ");
    }
}