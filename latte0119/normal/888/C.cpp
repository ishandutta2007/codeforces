#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}


signed main(){
    string S;cin>>S;

    int ans=1001001001;
    for(char c='a';c<='z';c++){
        vint pos;
        pos.pb(-1);
        rep(i,S.size())if(S[i]==c)pos.pb(i);
        pos.pb(S.size());

        int ma=0;
        for(int i=0;i+1<pos.size();i++)chmax(ma,pos[i+1]-pos[i]);
        chmin(ans,ma);
    }
    cout<<ans<<endl;
    return 0;
}