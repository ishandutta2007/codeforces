#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

char fld[10][10];

bool ok(){
    rep(i,4)rep(j,2)if(fld[i][j]=='x'&&fld[i][j+1]=='x'&&fld[i][j+2]=='x')return true;
    rep(i,2)rep(j,4)if(fld[i][j]=='x'&&fld[i+1][j]=='x'&&fld[i+2][j]=='x')return true;
    rep(i,2)rep(j,2)if(fld[i][j]=='x'&&fld[i+1][j+1]=='x'&&fld[i+2][j+2]=='x')return true;
    rep(i,2)for(int j=2;j<4;j++)if(fld[i][j]=='x'&&fld[i+1][j-1]=='x'&&fld[i+2][j-2]=='x')return true;
    return false;
}

signed main(){
    rep(i,4)cin>>fld[i];

    rep(i,4)rep(j,4){
        if(fld[i][j]!='.')continue;
        fld[i][j]='x';
        if(ok()){
            cout<<"YES"<<endl;
            return 0;
        }
        fld[i][j]='.';
    }
    cout<<"NO"<<endl;
    return 0;
}