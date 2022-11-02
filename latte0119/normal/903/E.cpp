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

int N,K;
string S[5555];

bool flag;

int val[5555];

bool check(int x,int y){
    for(int i=1;i<K;i++){
        int c=val[i];
        c+=S[0][x]!=S[i][x];
        c+=S[0][y]!=S[i][y];
        c-=S[0][x]!=S[i][y];
        c-=S[0][y]!=S[i][x];
        if(c!=2&&!(c==0&&flag))return false;
    }
    return true;
}

signed main(){
    cin>>K>>N;
    rep(i,K)cin>>S[i];

    vector<string>latte;
    rep(i,K){
        string s=S[i];
        sort(all(s));
        latte.pb(s);
    }

    sort(all(latte));latte.erase(unique(all(latte)),latte.end());
    if(latte.size()!=1){
        cout<<-1<<endl;
        return 0;
    }

    vint cnt(26);
    rep(i,N)cnt[S[0][i]-'a']++;
    flag=*max_element(all(cnt))>1;

    for(int i=1;i<K;i++){
        int cnt=0;
        rep(j,N)if(S[0][j]!=S[i][j])cnt++;
        val[i]=cnt;
    }

    rep(i,N){
        for(int j=i+1;j<N;j++){
            swap(S[0][i],S[0][j]);
            if(check(i,j)){
                cout<<S[0]<<endl;
                return 0;
            }
            swap(S[0][i],S[0][j]);
        }
    }
    cout<<-1<<endl;
    return 0;
}