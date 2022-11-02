#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const ll LONGINF=4e18;
const double eps=1e-9;

template<typename T>void swap(T *x1,T *x2){
    T t;
    t=*x1;
    *x1=*x2;
    *x2=t;
}

bool g=false,st[55][55];
int t[55][55];


void deep(int i,int j,int i1,int j1){
    st[i][j]=false;
    if(t[i-1][j]==t[i][j]){
        if(st[i-1][j]) deep(i-1,j,i,j);
        else if(i-1!=i1||j!=j1) g=true;
    }
    if(t[i+1][j]==t[i][j]){
        if(st[i+1][j]) deep(i+1,j,i,j);
        else if(i+1!=i1||j!=j1) g=true;
    }
    if(t[i][j-1]==t[i][j]){
        if(st[i][j-1]) deep(i,j-1,i,j);
        else if(i!=i1||j-1!=j1) g=true;
    }
    if(t[i][j+1]==t[i][j]){
        if(st[i][j+1]) deep(i,j+1,i,j);
        else if(i!=i1||j+1!=j1) g=true;
    }
}






void solve(int n){
    int i,j,m;
    scanf("%d",&m);
    For(i,55){
        For(j,55){
            t[i][j]=-1;
            st[i][j]=true;
        }
    }
    For(i,n){
        getchar();
        For(j,m){
            t[i+1][j+1]=getchar()-'A';
        }
    }
    For(i,n){
        For(j,m){
            if(st[i+1][j+1]) deep(i+1,j+1,-1,-1);
        }
    }
    if(g){
        printf("Yes");
    }
    else{
        printf("No");
    }


#ifndef ONLINE_JUDGE
    printf("\n\nTime in ms: %.0lf",(double)clock() / CLOCKS_PER_SEC * 1000);
#endif
}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[100100];
    string s;
    while(scanf("%d",&n)==1) solve(n);
    /*printf("2000 1999 1\n");
    For(n,1999){
        printf("%d %d 1000000000000000\n",n+1,n+2);
    }*/
    return 0;
}