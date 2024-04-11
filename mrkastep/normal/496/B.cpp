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
    int i,j,x,n,t;
    vector<int> a,min;
    char c;
    scanf("%d",&n);
    getchar();
    For(i,n){
        c=getchar();
        a.pb(c-'0');
    }
    min=a;
    For(i,n){
        t=a[0];
        For(j,n-1) a[j]=a[j+1];
        a[n-1]=t;
        For(j,10){
            For(x,n){
                a[x]=(a[x]+1)%10;
            }
            if(a<min) min=a;
        }
    }
    For(i,n){
        printf("%d",min[i]);
    }







    return 0;
}