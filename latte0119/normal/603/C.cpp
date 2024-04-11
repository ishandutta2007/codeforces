#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

int N,K;

int G(int p){
    if(K&1){
        if(p<=3)return p&1;
        if(p&1)return 0;
        if(p==4)return 2;
        int tmp=G(p/2);
        if(tmp<=1)return tmp+1;
        return 1;
    }
    else{
        if(p<=2)return p;
        return (p+1)&1;
    }
}

int main(){
    scanf("%d%d",&N,&K);

    int X=0;

    rep(i,N){
        int p;scanf("%d",&p);
        X^=G(p);
    }

    if(X)puts("Kevin");
    else puts("Nicky");

    return 0;
}