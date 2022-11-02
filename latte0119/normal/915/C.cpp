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

string latte(vint c){
    string ret;
    rep(i,10)ret+=string(c[i],'0'+i);
    return ret;
}

signed main(){
    string a,b;
    cin>>a>>b;

    if(a.size()<b.size()){
        sort(all(a));reverse(all(a));
        cout<<a<<endl;
        return 0;
    }

    vint cnt(10);
    rep(i,a.size())cnt[a[i]-'0']++;

    string ans;
    rep(i,a.size()){
        for(int j=9;j>=0;j--){
            if(cnt[j]==0)continue;
            cnt[j]--;
            string tmp=ans+string(1,'0'+j)+latte(cnt);
            if(tmp<=b){
                ans+=string(1,'0'+j);
                break;
            }
            cnt[j]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}