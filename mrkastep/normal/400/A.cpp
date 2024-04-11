#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int ind[6];
bool ans[13];
char s[13];

void count(){
    int i,j,t,b=0;
    bool a,c;
    scanf("%s",&s);
    For(i,13) ans[i]=false;
    For(i,6){
        For(j,ind[5-i]){
            a=true;
            For(t,ind[i]){
                if(s[j+t*ind[5-i]]!='X') a=false;
            }
            ans[i]=ans[i]||a;
        }
        if(ans[i]) b++;
    }
    printf("%d ",b);
    For(i,6) if(ans[i]) printf("%dx%d ",ind[i],ind[5-i]);
    printf("\n");
}

void solve(int n){
    int i;
    ind[0]=1;
    ind[1]=2;
    ind[2]=3;
    ind[3]=4;
    ind[4]=6;
    ind[5]=12;
    For(i,n) count();
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}