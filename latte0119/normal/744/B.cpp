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

int p[]={2,3,5};

int val1[2][3][1000],w1=180;
int val2[2][3][1000],w2=30;
int val3[3][5][1000];
signed main(){
    int N;
    scanf("%lld",&N);

    fill_n(**val1,2*3*1000,INT_MAX);
    fill_n(**val2,2*3*1000,INT_MAX);
    fill_n(**val3,3*5*1000,INT_MAX);

    for(int i=0;i<2;i++){
        for(int j=0;j<p[i];j++){
            vint v;
            for(int k=0;k<N;k++){
                int g=k/w1;
                if(g%p[i]!=j)continue;
                v.pb(k);
            }
            if(v.size()==0)continue;
            printf("%lld\n",(int)v.size());
            rep(k,v.size()){
                if(k)printf(" ");
                printf("%lld",v[k]+1);
            }
            puts("");
            fflush(stdout);
            for(int k=0;k<N;k++)scanf("%lld",&val1[i][j][k]);
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<p[i];j++){
            vint v;
            for(int k=0;k<N;k++){
                int g=k/w2;
                if(g%p[i]!=j)continue;
                v.pb(k);
            }
            if(v.size()==0)continue;
            printf("%lld\n",(int)v.size());
            rep(k,v.size()){
                if(k)printf(" ");
                printf("%lld",v[k]+1);
            }
            puts("");
            fflush(stdout);
            for(int k=0;k<N;k++)scanf("%lld",&val2[i][j][k]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<p[i];j++){
            vint v;
            for(int k=0;k<N;k++){
                int g=k;
                if(g%p[i]!=j)continue;
                v.pb(k);
            }
            if(v.size()==0)continue;
            printf("%lld\n",(int)v.size());
            rep(k,v.size()){
                if(k)printf(" ");
                printf("%lld",v[k]+1);
            }
            puts("");
            fflush(stdout);
            for(int k=0;k<N;k++)scanf("%lld",&val3[i][j][k]);
        }
    }

    puts("-1");
    rep(i,N){
        int ans=INT_MAX;
        for(int j=0;j<2;j++){
            for(int k=0;k<p[j];k++){
                int g=i/w1;
                if(g%p[j]==k)continue;
                chmin(ans,val1[j][k][i]);
            }
        }

        for(int j=0;j<2;j++){
            for(int k=0;k<p[j];k++){
                int g=i/w2;
                if(g%p[j]==k)continue;
                chmin(ans,val2[j][k][i]);
            }
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<p[j];k++){
                int g=i;
                if(g%p[j]==k)continue;
                chmin(ans,val3[j][k][i]);
            }
        }
        if(i)printf(" ");
        printf("%lld",ans);
    }
    puts("");
}