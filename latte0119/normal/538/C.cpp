#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

int N,M;
int d[100000],h[100000];

int main(){
    scanf("%d%d",&N,&M);
    rep(i,M)scanf("%d%d",&d[i],&h[i]);


    int ma=0;

    for(int i=1;i<M;i++){
        int dd=d[i]-d[i-1];
        int dh=abs(h[i]-h[i-1]);
        if(dh>dd){
            puts("IMPOSSIBLE");
            return 0;
        }
        ma=max(ma,(dd-dh)/2+max(h[i],h[i-1]));
    }

    ma=max(ma,max(d[0]-1+h[0],h[M-1]+(N-d[M-1])));

    printf("%d\n",ma);
    return 0;
}