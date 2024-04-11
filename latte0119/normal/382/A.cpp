#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
    string a,b;
    cin>>a>>b;
    int x=find(all(a),'|')-a.begin();
    int y=a.size()-x-1;

    int d=abs(x-y);
    if(b.size()<d||(b.size()-d)&1){
        cout<<"Impossible"<<endl;
        return 0;
    }
    int l=(b.size()-d)/2;
    if(x<y){
        a=b.substr(0,d+l)+a;
        a=a+b.substr(d+l,l);
    }
    else{
        a=b.substr(0,l)+a;
        a=a+b.substr(l,d+l);
    }
    cout<<a<<endl;
    return 0;
}