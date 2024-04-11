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

signed main(){
    string S;
    cin>>S;

    rep(i,S.size()){
        for(int j=i+2;j<S.size();j++){
            if(S[i]!=S[j])continue;
            S=S.substr(0,j)+S.substr(j+1,S.size()-j-1);
            int t=(j-i+1)/2;
            int s=13-t;
            if(i<=s){
                if(s-i>0)rotate(S.begin(),S.begin()+26-(s-i),S.end());
            }
            else{
                rotate(S.begin(),S.begin()+i-s,S.end());
            }
            cout<<S.substr(0,13)<<endl;
            string r=S.substr(13,13);
            reverse(all(r));
            cout<<r<<endl;
            return 0;
        }
    }

    cout<<"Impossible"<<endl;
    return 0;
}

//ABCDEFGHIJKLMNOPQRSTUVWXYZE