#include<cstdio>
#include<iostream>

using namespace std;
typedef long long ll;

inline ll cube(int i){return (ll)i*i*i;}
int biggest(ll x){
    int lb=0,ub=100000+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(cube(mid)<=x)lb=mid;
        else ub=mid;
    }
    return lb;
}

pair<ll,ll>dfs(ll X){
    if(X<=7)return {X,X};
    int v=biggest(X);

    pair<ll,ll>p1=dfs(X-cube(v));p1.first++;p1.second+=cube(v);
    pair<ll,ll>p2=dfs(cube(v)-cube(v-1)-1);p2.first++;p2.second+=cube(v-1);
    return max(p1,p2);
}

int main(){
    ll X;
    scanf("%lld",&X);
    pair<ll,ll>p=dfs(X);
    printf("%lld %lld\n",p.first,p.second);
    return 0;
}