#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

const int mod=1e9+7;

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int a[111],i,m=1e9,j,n,g=-1,t;
    scanf("%d",&n);
    For(i,n) scanf("%d",&a[i]);
    FOR(i,1,n-1){
        t=-1;
        For(j,n-1){
            if(j!=i){
                t=max(t,(j+1==i?a[j+2]:a[j+1])-a[j]);
                
            }
        }
        if(t<m){
            g=i;
            m=t;
        }
    }
    printf("%d",m);







}