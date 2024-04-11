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

string uku="UDLR";

signed main(){
    int N;cin>>N;
    string S;
    cin>>S;
    vint cnt(4);
    rep(i,N){
        int d=find(all(uku),S[i])-uku.begin();
        cnt[d]++;
    }

    int ans=0;
    for(int i=0;i<4;i+=2){
        ans+=2*min(cnt[i],cnt[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}