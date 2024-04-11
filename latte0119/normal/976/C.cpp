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
	int N;cin>>N;
	vector<int>L(N),R(N);
	rep(i,N)cin>>L[i]>>R[i];

	vector<tuple<int,int,int>>ord;
	rep(i,N)ord.eb(R[i],-L[i],i);
	sort(all(ord));
	
	pint ma(-1,-1);
	rep(i,N){
		int r,l,k;
		tie(r,l,k)=ord[i];

		if(ma.fi>=L[k]){
			cout<<ma.se+1<<" "<<k+1<<endl;
			return 0;
		}
		chmax(ma,pint(L[k],k));
	}

	cout<<-1<<" "<<-1<<endl;
}