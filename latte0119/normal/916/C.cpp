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

const int ISPRIME_SIZE=11111111;
bool isprime[ISPRIME_SIZE];
struct isprime_exec{
    isprime_exec(){
        for(int i=0;i<ISPRIME_SIZE;i++)isprime[i]=true;
        isprime[0]=isprime[1]=false;
        for(int i=2;i<ISPRIME_SIZE;i++){
            if(!isprime[i])continue;
            for(int j=i+i;j<ISPRIME_SIZE;j+=i)isprime[j]=false;
        }
    }
}isprimeexec;

int N,M;

signed main(){
    cin>>N>>M;

    int p=N-1;
    while(!isprime[p])p++;

    printf("%lld %lld\n",p,p);
    vector<int>A,B,C;
    rep(i,N-1){
        A.pb(i);
        B.pb(i+1);
        if(i==0)C.pb(p-(N-2));
        else C.pb(1);
    }

    M-=N-1;
    for(int i=0;i<N&&M;i++){
        for(int j=i+2;j<N&&M;j++){
            M--;
            A.pb(i);B.pb(j);C.pb(1000000000);
        }
    }

    rep(i,A.size())printf("%lld %lld %lld\n",A[i]+1,B[i]+1,C[i]);
    return 0;
}