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

int toint(string s){
    stringstream ss(s);int d;ss>>d;return d;
}

int N;

bool ok(string s){
    int t=toint(s);
    if(t>=N)return false;
    if(s.size()>12)return false;
    if(s.size()>=2&&s[0]=='0')return false;
    return true;
}

signed main(){
    cin>>N;
    string S;cin>>S;
    reverse(all(S));
    vint ans;

    int cur=0;
    while(cur<S.size()){
        int next;
        for(int i=cur+1;i<=S.size();i++){
            string s=S.substr(cur,i-cur);
            reverse(all(s));
            if(ok(s))next=i;
        }
        string s=S.substr(cur,next-cur);
        reverse(all(s));
        int t=toint(s);
        ans.pb(t);
        cur=next;
    }
    int val=0;
    for(int i=ans.size()-1;i>=0;i--)val=val*N+ans[i];
    cout<<val<<endl;
    return 0;
}