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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
int x[1111],y[1111];
int s[1111][1111];
vint xs,ys;
int get(int yy,int xx){
    if(yy<0||yy>=ys.size()||xx<0||xx>=xs.size())return 0;
    return s[yy][xx];
}

signed main(){
    cin>>N;
    rep(i,N+1)cin>>x[i]>>y[i];

    rep(i,N)xs.pb(x[i]),ys.pb(y[i]);
    sort(all(xs));xs.erase(unique(all(xs)),xs.end());
    sort(all(ys));ys.erase(unique(all(ys)),ys.end());
    rep(i,N+1){
        x[i]=lower_bound(all(xs),x[i])-xs.begin();
        y[i]=lower_bound(all(ys),y[i])-ys.begin();
    }

    rep(i,N){
        if(y[i]==y[i+1])continue;
        int hoge=min(y[i],y[i+1]);
        int piyo=max(y[i],y[i+1]);
        for(int j=hoge;j<piyo;j++)s[j][x[i]]++;
    }
    rep(i,ys.size()){
        rep(j,xs.size()){
            s[i][j]&=1;
            s[i][j+1]+=s[i][j];
        }
    }

    int cnt=0;
    rep(i,N){
        if(x[i]<x[i+1]){
            if(get(y[i+1],x[i+1])&&get(y[i+1]-1,x[i+1]))cnt++;
        }
        else if(x[i]>x[i+1]){
            if(get(y[i+1],x[i+1]-1)&&get(y[i+1]-1,x[i+1]-1))cnt++;
        }
        else if(y[i]<y[i+1]){
            if(get(y[i+1],x[i+1])&&get(y[i+1],x[i+1]-1))cnt++;
        }
        else{
            if(get(y[i+1]-1,x[i+1])&&get(y[i+1]-1,x[i+1]-1))cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}