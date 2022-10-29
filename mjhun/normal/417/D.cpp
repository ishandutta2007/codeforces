#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define INF (1LL<<62)
using namespace std;

typedef long long ll;

ll dp[1<<20];

struct frnd{
    int q,c,p;
};

frnd fs[128];

bool comp(frnd f1, frnd f2){
    return f1.q<f2.q;
}

int main(){
    int n,m,b,i,j;
    scanf("%d %d %d",&n,&m,&b);
    for(i=0;i<n;++i){
        int k,x,q,c,p=0;
        scanf("%d %d %d",&c,&q,&k);
        for(j=0;j<k;++j){
            scanf("%d",&x);
            p|=1<<(x-1);
        }
        fs[i].q=q;
        fs[i].c=c;
        fs[i].p=p;
    }
    sort(fs,fs+n,comp);

    for(j=0;j<(1<<m);++j){
        dp[j]=INF;
    }
    dp[(1<<m)-1]=0;
    ll r=INF;
    for(i=0;i<n;++i){
        for(j=0;j<(1<<m);++j){
            dp[j]=min(dp[j],((ll)fs[i].c)+dp[j|fs[i].p]);
        }
        r=min(r,dp[0]+((ll)b)*fs[i].q);
    }
    cout<<((r>=INF)?(-1):r)<<endl;
    return 0;
}