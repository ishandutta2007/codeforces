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
	string S;
	cin>>S;
	int N=S.size();
	vector<char>mi(N);
	mi[N-1]='z';
	for(int i=N-2;i>=0;i--){
		mi[i]=min(S[i+1],mi[i+1]);
	}
	string ans;
	stack<char>stk;
	rep(i,N){
		stk.push(S[i]);
		while(stk.size()&&mi[i]>=stk.top()){
			ans+=stk.top();
			stk.pop();
		}
	}

	cout<<ans<<endl;
	return 0;
}