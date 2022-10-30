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

string lis="aiueoy";

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;
    vint P(N);rep(i,N)cin>>P[i];

    bool ok=true;
    cin.ignore();
    rep(k,N){
        string str;
        getline(cin,str);
        stringstream ss(str);
        string s;
        int cnt=0;
        while(ss>>s){
            rep(i,s.size())if(find(all(lis),s[i])!=lis.end())cnt++;
        }
        if(cnt!=P[k]){
            ok=false;
        }
    }

    cout<<(ok?"YES":"NO")<<endl;
    return 0;
}