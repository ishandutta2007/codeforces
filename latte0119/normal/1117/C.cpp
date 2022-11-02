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

const int INF=1001001001001001001ll;

int sy,sx,tx,ty;
int N;
string D;

bool check(int t){
    int x=tx-sx;
    int y=ty-sy;

    rep(i,N){
        int dy,dx;
        if(D[i]=='U'){dx=0;dy=-1;}
        if(D[i]=='D'){dx=0;dy=1;}
        if(D[i]=='L'){dx=1;dy=0;}
        if(D[i]=='R'){dx=-1;dy=0;}
        int cnt=t/N+(i<(t%N));
        x+=cnt*dx;
        y+=cnt*dy;
    }

    x=abs(x);
    y=abs(y);
    if(x+y>t)return false;
    return true;
}

signed main(){
    cin>>sx>>sy>>tx>>ty;
    cin>>N;
    cin>>D;

    int lb=0,ub=INF;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid;
        else lb=mid;
    }
    if(ub==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ub<<endl;
    }
    return 0;
}