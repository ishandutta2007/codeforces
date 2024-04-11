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

int A[555555];
int b=222222;

signed main(){
    int N,K;

    cin>>N>>K;
    rep(i,60)if(N>>i&1)A[i+b]++;

    int s=accumulate(A,A+555555,0ll);
    if(s>K){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=555555-1;i>=0;i--){
        if(s+A[i]<=K){
            s+=A[i];
            A[i-1]+=A[i]*2;
            A[i]=0;
        }
        else{
            break;
        }
    }

    int p;
    rep(i,555555)if(A[i]){
        p=i;
        break;
    }
    while(s<K){
        A[p]--;
        A[p-1]+=2;
        p--;
        s++;
    }

    puts("Yes");
    vint v;
    for(int i=555555-1;i>=0;i--){
        rep(j,A[i])v.pb(i-b);
    }


    rep(i,v.size()){
        if(i)printf(" ");
        printf("%lld",v[i]);
    }
    puts("");
    return 0;
}