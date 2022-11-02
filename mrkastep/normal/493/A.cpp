#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long



void solve(){
    char h[100],a[100],c,c1;
    int i,n,t,num;
    bool h1[100],a1[100];
    int th[100],ta[100];
    gets(h);
    gets(a);
    For(i,100){
        h1[i]=a1[i]=false;
        th[i]=ta[i]=-1;
    }
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&t);
        getchar();
        c=getchar();
        scanf("%d",&num);
        getchar();
        c1=getchar();
        if(c=='h'){
            if(!h1[num]){
                if(c1=='r'){
                    h1[num]=true;
                    th[num]=t;
                    printf("%s %d %d\n",h,num,t);
                }
                else{
                    if(th[num]!=-1){
                        h1[num]=true;
                        printf("%s %d %d\n",h,num,t);
                    }
                    th[num]=t;
                }
            }
        }
        else{
            if(!a1[num]){
                if(c1=='r'){
                    a1[num]=true;
                    ta[num]=t;
                    printf("%s %d %d\n",a,num,t);
                }
                else{
                    if(ta[num]!=-1){
                        a1[num]=true;
                        printf("%s %d %d\n",a,num,t);
                    }
                    ta[num]=t;
                }
            }
        }
    }




}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    
    solve();
    
    return 0;
}