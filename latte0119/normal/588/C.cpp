#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back

int N;
int cnt[1010101];
int main(){

    scanf("%d",&N);
    rep(i,N){
        int w;scanf("%d",&w);
        cnt[w]++;
    }
    int ans=0;
    for(int i=0;i<1010101-1;i++){
        cnt[i+1]+=cnt[i]/2;
        cnt[i]%=2;
        ans+=cnt[i];
    }

    printf("%d\n",ans);

    return 0;
}