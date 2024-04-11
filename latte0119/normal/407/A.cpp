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

int latte[1111111];

signed main(){
    for(int i=1;i<=1000;i++)latte[i*i]=i;

    int a,b;
    cin>>a>>b;

    vpint lis1,lis2;

    for(int i=1;i<=a;i++){
        int x=a*a-i*i;
        if(latte[x])lis1.pb({i,latte[x]});
        lis1.pb({i,-latte[x]});
    }

    for(int i=1;i<=b;i++){
        int x=b*b-i*i;
        if(latte[x])lis2.pb({i,latte[x]});
        lis2.pb({i,-latte[x]});
    }


    for(auto &p:lis1){
        for(auto &q:lis2){
            //if((p.fi-q.fi)*(p.fi-q.fi)+(p.se-q.se)*(p.se-q.se)!=a*a+b*b)continue;
            if(p.fi*q.fi+p.se*q.se!=0)continue;
            if(p.fi==q.fi)continue;

            cout<<"YES"<<endl;
            cout<<0<<" "<<0<<endl;
            cout<<p.fi<<" "<<p.se<<endl;
            cout<<q.fi<<" "<<q.se<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}