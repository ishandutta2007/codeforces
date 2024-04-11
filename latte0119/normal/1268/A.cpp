#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

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

int N,K;
string S;
signed main(){
	cin>>N>>K;
	cin>>S;

	string tmp(N,'0');
	rep(i,K)tmp[i]=S[i];
	for(int i=K;i<N;i++)tmp[i]=tmp[i-K];
	if(tmp>=S){
		cout<<N<<endl;
		cout<<tmp<<endl;
		return 0;
	}

	for(int i=K-1;i>=0;i--){
		if(S[i]!='9'){
			S[i]++;
			for(int j=i+1;j<K;j++)S[j]='0';
			break;
		}
	}
	for(int i=K;i<N;i++)S[i]=S[i-K];
	cout<<N<<endl;
	cout<<S<<endl;
	return 0;
}