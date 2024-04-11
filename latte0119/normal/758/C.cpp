#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int H,W,K,X,Y;

int cnt[111][111];
signed main(){
    cin>>H>>W>>K>>Y>>X;
    Y--;X--;

    if(H==1){
        cout<<(K+W-1)/W<<" ";
        cout<<K/W<<" ";
        cout<<K/W+(X<K%W)<<endl;
        return 0;
    }

    int tmp=K/(W*(2*H-2));
    K%=W*(2*H-2);
    rep(i,W)cnt[0][i]=cnt[H-1][i]=tmp;
    for(int i=1;i+1<H;i++)rep(j,W)cnt[i][j]=tmp*2;
    rep(i,H)rep(j,W)if(K){
        cnt[i][j]++;
        K--;
    }

    for(int i=H-2;i>=0;i--)rep(j,W)if(K){
        cnt[i][j]++;
        K--;
    }

    int ma=LLONG_MIN,mi=LLONG_MAX;
    rep(i,H)rep(j,W){
        chmax(ma,cnt[i][j]);
        chmin(mi,cnt[i][j]);
    }
    cout<<ma<<" "<<mi<<" "<<cnt[Y][X]<<endl;
    return 0;
}