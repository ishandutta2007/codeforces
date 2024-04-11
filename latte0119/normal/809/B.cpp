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

int N,K;

bool q(int a,int b){
    cout<<1<<" "<<a+1<<" "<<b+1<<endl;
    string s;cin>>s;
    return s=="TAK";
}

signed main(){
    cin>>N>>K;

    int lb=-1,ub=N-1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(q(mid,mid+1))ub=mid;
        else lb=mid;
    }

    int x=ub;
    int y=-1;
    if(x+1!=N){
        lb=x+1;
        ub=N;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(q(mid,mid-1))lb=mid;
            else ub=mid;
        }
        if(lb>x+1){
            y=lb;
        }
        else{
            if(q(x+1,x))y=x+1;
        }
    }

    if(x>0){
        int lb=0,ub=x;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(q(x-1-mid,x-mid))lb=mid;
            else ub=mid;
        }
        if(lb>0){
            y=x-1-lb;
        }
        else{
            if(q(x-1,x))y=x-1;
        }
    }

    cout<<2<<" "<<x+1<<" "<<y+1<<endl;
    return 0;
}