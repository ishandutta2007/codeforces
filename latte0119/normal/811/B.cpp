#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
int A[11111];

signed main(){
    scanf("%d%d",&N,&M);
    rep(i,N)scanf("%d",&A[i]);

    rep(i,M){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        l--;x--;

        int cnt=0;
        for(int j=l;j<r;j++)if(A[j]<A[x])cnt++;
        x-=l;
        if(cnt==x)puts("Yes");
        else puts("No");
    }

    return 0;
}