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

int N,S,X;

signed main(){
    srand((unsigned)time(NULL));

    cin>>N>>S>>X;
    vint ord;
    rep(i,N)ord.pb(i+1);
    random_shuffle(all(ord));
    rep(i,N)if(ord[i]==S)swap(ord[i],ord[0]);

    int y=-1,argy=-1;
    rep(i,min(900ll,N)){
        cout<<"? "<<ord[i]<<endl;
        int val,nex;
        cin>>val>>nex;
        if(val<X&&y<val){
            y=val;
            argy=ord[i];
        }
    }

    if(argy==-1){
        cout<<"? "<<S<<endl;
        cin>>y>>argy;
        cout<<"! "<<y<<endl;
        return 0;
    }

    while(true){
        if(argy==-1){
            cout<<"! "<<-1<<endl;
            return 0;
        }
        cout<<"? "<<argy<<endl;
        cin>>y>>argy;
        if(y>=X){
            cout<<"! "<<y<<endl;
            return 0;
        }
    }
    return 0;
}