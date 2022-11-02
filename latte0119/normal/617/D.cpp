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

signed main(){
    int x[3],y[3];
    set<int>X,Y;
    rep(i,3){
        cin>>x[i]>>y[i];
        X.insert(x[i]);
        Y.insert(y[i]);
    }

    if(X.size()==1||Y.size()==1)cout<<1<<endl;
    else if(X.size()==3&&Y.size()==3)cout<<3<<endl;
    else{
        if(Y.size()==2)rep(i,3)swap(x[i],y[i]);
        int d;
        if(x[0]==x[1])d=x[0];
        else if(x[0]==x[2])d=x[0];
        else d=x[1];

        int a=LLONG_MAX,b=LLONG_MIN;
        rep(i,3)if(x[i]==d){
            chmin(a,y[i]);
            chmax(b,y[i]);
        }
        rep(i,3)if(x[i]!=d){
            if(a<y[i]&&y[i]<b)cout<<3<<endl;
            else cout<<2<<endl;
            return 0;
        }
    }
    return 0;
}