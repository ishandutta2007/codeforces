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

void solve(){
	int N,K;
	cin>>N>>K;
	string S;cin>>S;


	string T;
	rep(i,K-1)T+="()";

	T+=string((N-T.size())/2,'(');
	T+=string(N-T.size(),')');

	vpint ans;

	for(int i=0;i<N;i++){
		if(S[i]==T[i])continue;
		int j=i;
		while(S[j]!=T[i])j++;
		ans.eb(i,j);
		reverse(S.begin()+i,S.begin()+j+1);
	}

	cout<<ans.size()<<endl;
	for(auto &p:ans)cout<<p.fi+1<<" "<<p.se+1<<endl;
}

signed main(){
	int T;scanf("%lld",&T);
	while(T--)solve();
	return 0;
}