#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int table[1<<9][1<<9];

void rec(int N,int y,int x,int s){
    if(N==1){
        table[y][x]=s;
    }
    else{
        rec(N/2,y,x,s);
        rec(N/2,y+N/2,x,s);
        rec(N/2,y,x+N/2,s);
        rec(N/2,y+N/2,x+N/2,-s);
    }
}

int main(){
    int K;
    while(~scanf("%d",&K)){
        rec(1<<K,0,0,1);
        rep(i,1<<K){
            rep(j,1<<K)putchar(table[i][j]==1?'+':'*');
            puts("");
        }
    }
    return 0;
}