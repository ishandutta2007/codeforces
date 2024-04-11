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
  
bool check(string s){
    int i;
    For(i,s.length()){
        if(s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
}


int p[111][111];

int fs(int v,int c){
    if(p[c][v]==v) return v;
    return p[c][v]=fs(p[c][v],c);
}

void us(int a,int b,int c){
    a=fs(a,c);
    b=fs(b,c);
    if(a==b) return;
    p[c][a]=b;
}









void solve(int n){
    int m,a,b,c,i,j;
    scanf("%d",&m);
    For(i,111){
        For(j,111){
            p[i][j]=j;
        }
    }
    For(i,m){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        c--;
        us(a,b,c);
    }
    scanf("%d",&m);
    For(i,m){
        c=0;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        For(j,111){
            if(fs(a,j)==fs(b,j)) c++;
        }
        printf("%d\n",c);
    }






    
  
#ifdef HOME
    printf("\n\nTime in ms: %.0lf",clock()*1000/CLOCKS_PER_SEC);
#endif
  
  
}
  
  
int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char s[20];
    string c;
    while(scanf("%d",&n)==1) solve(n);
  
    return 0;
}