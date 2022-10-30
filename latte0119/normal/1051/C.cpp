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

int N;
int S[111];

vint lis[111];
signed main(){
	cin>>N;
	rep(i,N)cin>>S[i];
	vint cnt(111);
	rep(i,N){
		cnt[S[i]]++;
		lis[S[i]].pb(i);
	}

	vint ei,uku;
	rep(i,111){
		if(cnt[i]==1){
			ei.pb(i);
		}
		else if(cnt[i]>2)uku.pb(i);
	}

	if(ei.size()%2&&uku.size()==0){
		cout<<"NO"<<endl;
		return 0;
	}
	if(ei.size()%2){
		ei.pb(uku.back());
	}
	string ans(N,'A');
	for(int i=1;i<ei.size();i+=2)ans[lis[ei[i]][0]]='B';
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	return 0;
}