#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=100000;

int N;
int A[SIZE],B[SIZE];
int val[SIZE+1];
signed main(){
    int mi=1001001001;
    vint lis;
    scanf("%d",&N);
    rep(i,N)scanf("%d%d",&A[i],&B[i]);
    vector<pint>vs;
    rep(i,N)vs.pb(pint(A[i],B[i]));
    sort(all(vs));
    rep(i,N)A[i]=vs[i].first,B[i]=vs[i].second;

    val[0]=N;
    rep(i,N){
        int l=lower_bound(A,A+N,A[i]-B[i])-A;
        val[i+1]=val[l]-1;
        mi=min(mi,val[i+1]);
    }

    printf("%d\n",mi);
    return 0;
}