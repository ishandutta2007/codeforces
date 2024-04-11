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

void solve(){
	string S;
	cin>>S;
	sort(all(S));
	if(S[0]!='0'){
		cout<<"cyan"<<endl;
		return;
	}
	for(int i=1;i<S.size();i++){
		int sum=0;
		for(int j=1;j<S.size();j++){
			if(i==j)sum+=S[j]-'0';
			else sum+=(S[j]-'0')*4;
		}
		sum%=6;
		if(sum==0){
			cout<<"red"<<endl;
			return;
		}
	}
	cout<<"cyan"<<endl;
}

signed main(){
	int N;cin>>N;
	while(N--)solve();
	return 0;
}