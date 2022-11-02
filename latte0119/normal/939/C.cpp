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

int N;
int A[222222];
int S[222222];
signed main(){
    cin>>N;
    rep(i,N){
        cin>>A[i];
        A[i+N]=A[i];
    }

    rep(i,2*N)S[i+1]=S[i]+A[i];

    int s,f;
    cin>>s>>f;
    s--;f--;
    int l=f-s;

    int ma=LLONG_MIN,ans;
    rep(i,N){
        int tmp=S[i+l]-S[i];
        if(ma<tmp){
            ma=tmp;
            ans=((s-i)%N+N)%N+1;
        }
        else if(ma==tmp&&ans>((s-i)%N+N)%N+1)ans=((s-i)%N+N)%N+1;
    }
    cout<<ans<<endl;
    return 0;
}