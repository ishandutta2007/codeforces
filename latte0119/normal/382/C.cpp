#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
int A[100000];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    if(N==1){
        puts("-1");
        return 0;
    }
    sort(A,A+N);
    vint ds;
    rep(i,N-1)ds.pb(A[i+1]-A[i]);
    sort(all(ds));

    if(ds[0]==ds.back()){
        if(ds[0]==0){
            puts("1");
            printf("%lld\n",A[0]);
        }
        else if(N==2&&(A[0]+A[1])%2==0){
            puts("3");
            printf("%lld %lld %lld\n",A[0]-ds[0],(A[0]+A[1])/2,A[1]+ds[0]);
        }
        else{
            puts("2");
            printf("%lld %lld\n",A[0]-ds[0],A[N-1]+ds[0]);
        }
    }

    else if(ds[0]==ds[ds.size()-2]&&ds[0]*2==ds.back()){
        rep(i,N-1)if(A[i+1]-A[i]==ds.back()){
            puts("1");
            printf("%lld\n",(A[i+1]+A[i])/2);
        }
    }
    else{
        puts("0");
    }
    return 0;
}