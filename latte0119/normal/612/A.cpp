#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    int n,p,q;string s;cin>>n>>p>>q>>s;
    rep(i,101)rep(j,101){
        if(i*p+j*q!=n)continue;
        cout<<i+j<<endl;
        rep(k,i){
            cout<<s.substr(0,p)<<endl;
            s=s.substr(p,s.size()-p);
        }
        rep(k,j){
            cout<<s.substr(0,q)<<endl;
            s=s.substr(q,s.size()-q);
        }
        return 0;
    }

    cout<<-1<<endl;
    return 0;
}