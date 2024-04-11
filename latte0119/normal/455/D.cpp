#include<bits/stdc++.h>
using namespace std;

#define int long long

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

const int MN=100000;
const int B=350;

int N,Q;
int A[MN];


deque<int>d[(MN+B-1)/B];
int cnt[(MN+B-1)/B][100000];

signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        A[i]--;
        d[i/B].pb(A[i]);
        cnt[i/B][A[i]]++;
    }

    scanf("%lld",&Q);
    int lastans=0;

    while(Q--){
        int t;
        int l,r,k;
        scanf("%lld%lld%lld",&t,&l,&r);
        if(t==2)scanf("%lld",&k);
        l=(l+lastans-1+N)%N+1;
        r=(r+lastans-1+N)%N+1;
        k=(k+lastans-1+N)%N+1;

        if(l>r)swap(l,r);

        l--;k--;

        if(t==1){
            if(l/B==r/B){
                int ll=l%B;
                int rr=r%B;
                rotate(d[l/B].begin()+ll,d[l/B].begin()+rr-1,d[l/B].begin()+rr);
                continue;
            }

            int pre=d[l/B].back();
            d[l/B].pop_back();
            cnt[l/B][pre]--;
            for(int i=l/B+1;i*B<r;i++){
                if((i+1)*B<=r){
                    cnt[i][pre]++;
                    d[i].push_front(pre);
                    pre=d[i].back();
                    d[i].pop_back();
                    cnt[i][pre]--;
                }
                else{
                    cnt[i][pre]++;
                    d[i].push_front(pre);
                    if(r-i*B!=r%B){
                        for(;;);
                    }
                    pre=d[i][r-i*B];
                    d[i].erase(d[i].begin()+(r-i*B));
                    cnt[i][pre]--;
                }
            }

            cnt[l/B][pre]++;
            d[l/B].insert(d[l/B].begin()+l%B,pre);
        }
        else{
            lastans=0;
            for(int i=l/B;i*B<r;i++){
                if(l<=i*B&&(i+1)*B<=r)lastans+=cnt[i][k];
                else{
                    for(int j=0;j<d[i].size();j++){
                        if(l<=i*B+j&&i*B+j<r)lastans+=(d[i][j]==k);
                    }
                }
            }
            printf("%lld\n",lastans);
        }
    }
}