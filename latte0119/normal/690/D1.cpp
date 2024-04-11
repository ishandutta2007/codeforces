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


int H,W;
char fld[100][100];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

signed main(){
    cin>>H>>W;
    string s;
    rep(i,H)cin>>s;
    int cnt=0;
    rep(i,s.size()){
        if(s[i]=='B'&&(i==0||s[i-1]=='.'))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}