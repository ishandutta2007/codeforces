#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int n,m;

int main(){
    cin>>n>>m;
    set<int>s;
    rep(i,n){
        int x;cin>>x;
        rep(j,x){
            int a;cin>>a;s.insert(a);
        }
    }
    if(s.size()==m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}