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


//
//()
//ab
//O(log^2 N)fractional cascadingO(logN)

struct LayeredRangeTree{
    LayeredRangeTree(){}
    LayeredRangeTree(vector<int>&a){init(a);}
    void init(vector<int>&a){
        Size=1;while(Size<a.size())Size*=2;
        data.resize(Size*2);
        toL.resize(Size*2);
        toR.resize(Size*2);


        for(int i=0;i<a.size();i++){
            data[i+Size-1].push_back(a[i]);
        }

        for(int i=Size-2;i>=0;i--){
            data[i].resize(data[i*2+1].size()+data[i*2+2].size());
            toL[i].resize(data[i].size()+1);
            toR[i].resize(data[i].size()+1);
            if(data[i].size()==0)continue;
            merge(data[i*2+1].begin(),data[i*2+1].end(),data[i*2+2].begin(),data[i*2+2].end(),data[i].begin());

            {
                int cur=0;
                for(int j=0;j<data[i].size();j++){
                    while(cur<data[i*2+1].size()&&data[i][j]>data[i*2+1][cur])cur++;
                    toL[i][j]=cur;
                }
                toL[i][data[i].size()]=data[i*2+1].size();
            }

            {
                int cur=0;
                for(int j=0;j<data[i].size();j++){
                    while(cur<data[i*2+2].size()&&data[i][j]>data[i*2+2][cur])cur++;
                    toR[i][j]=cur;
                }
                toR[i][data[i].size()]=data[i*2+2].size();
            }
        }
    }

    int query(int a,int b,int c,int d){
        c=lower_bound(data[0].begin(),data[0].end(),c)-data[0].begin();
        d=lower_bound(data[0].begin(),data[0].end(),d)-data[0].begin();
        return query(a,b,c,d,0,0,Size);
    }

    int query(int a,int b,int c,int d,int k,int l,int r){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return d-c;
        return query(a,b,toL[k][c],toL[k][d],k*2+1,l,(l+r)/2)+query(a,b,toR[k][c],toR[k][d],k*2+2,(l+r)/2,r);
    }

    vector<vector<int>>data,toL,toR;
    int Size;
};

int N,K;
int X[111111],R[111111],F[111111];
vint lis[111111];
vint xs[111111];
LayeredRangeTree st[10010];

signed main(){
    scanf("%lld%lld",&N,&K);
    vector<tuple<int,int,int>>vec;
    rep(i,N){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        vec.pb(make_tuple(a,b,c));
    }
    sort(all(vec));
    rep(i,N)tie(X[i],R[i],F[i])=vec[i];


    rep(i,N)lis[F[i]].pb(i),xs[F[i]].pb(X[i]);
    for(int i=0;i<=10000;i++){
        if(lis[i].size()==0)continue;
        vint v;

        rep(j,lis[i].size())v.pb(X[lis[i][j]]+R[lis[i][j]]);
        st[i].init(v);
    }

    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=F[i]-K;j<=F[i]+K;j++){
            if(j<0)continue;
            if(lis[j].size()==0)continue;
            int l=lower_bound(all(xs[j]),X[i]-R[i])-xs[j].begin();
            int r=lower_bound(all(xs[j]),X[i])-xs[j].begin();

            if(l==r)continue;
            ans+=st[j].query(l,r,X[i],1001001001001001001ll);
        }
    }
    cout<<ans<<endl;
    return 0;
}