#include<bits/stdc++.h>
using namespace std;

//#define int long long

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

int N,K;
int A[500000];

signed main(){
    scanf("%d%d",&N,&K);
    rep(i,N)scanf("%d",&A[i]);

    map<int,int>M;
    int l=0;
    pint ans(0,0);
    rep(i,N){
        M[A[i]]++;
        while(M.size()>K){
            M[A[l]]--;
            if(M[A[l]]==0)M.erase(A[l]);
            l++;
        }
        if(ans.se-ans.fi<i-l)ans=pint(l,i);
    }
    printf("%d %d\n",ans.fi+1,ans.se+1);
    return 0;
}