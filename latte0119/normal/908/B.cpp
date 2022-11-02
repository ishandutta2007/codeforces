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

int dx[4],dy[4];

int H,W;
int sy,sx,gy,gx;
string fld[55];

string s;
bool check(){
    int y=sy,x=sx;
    rep(i,s.size()){
        int d=s[i]-'0';
        int ny=y+dy[d],nx=x+dx[d];
        if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='#')return false;
        y=ny;x=nx;
        if(fld[y][x]=='E')return true;
    }
    return false;
}
signed main(){
    cin>>H>>W;
    rep(i,H)cin>>fld[i];

    rep(i,H)rep(j,W){
        if(fld[i][j]=='S')sy=i,sx=j;
        if(fld[i][j]=='E')gy=i,gx=j;
    }
    cin>>s;
    vpint vec;
    vec.pb({-1,0});
    vec.pb({0,-1});
    vec.pb({0,1});
    vec.pb({1,0});
    sort(all(vec));
    int ans=0;
    do{
        rep(i,4)tie(dx[i],dy[i])=vec[i];
        if(check())ans++;
    }while(next_permutation(all(vec)));
    cout<<ans<<endl;
    return 0;
}