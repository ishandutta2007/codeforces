#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	vector<int> A(n);
	for(auto&x:A)cin>>x;
	int cnt=count(A.begin(),A.end(),0);
	int sum=accumulate(A.begin(),A.end(),0ll);
	if(cnt*k<abs(sum)){
		cout<<-1<<endl;
		return ;
	}
	if(sum<0){
		for(auto&x:A)x=-x;sum=-sum;
	}
	vector<int> Z,F;
	int pr=-1;
	for(int i=0;i<cnt;i++){
		if(sum>0)F.push_back(-k),sum-=k,pr=0;
		else Z.push_back(k),sum+=k,pr=1; 
	}
	if(pr!=-1)(pr?Z:F)[(pr?Z:F).size()-1]-=sum;
	auto calc=[](vector<int> A,vector<int> B){
		auto it=B.begin();
		int sum=0,L=0,R=0;
		for(auto x:A){
			if(!x)x=*it,++it;
			sum+=x;
			L=min(L,sum),R=max(R,sum);
		}
		return R-L+1;
	};
	int res=0;
	auto CALC=[&](vector<int> Z,vector<int> F){
		for(int i=0;i<=Z.size();i++){
			vector<int> nw;
			for(int j=0;j<i;j++)nw.push_back(Z[j]);
			for(auto x:F)nw.push_back(x);
			for(int j=i;j<Z.size();j++)nw.push_back(Z[j]);
			res=max(res,calc(A,nw));
		}
		for(int i=0;i<=Z.size();i++){
			vector<int> nw;
			for(int j=i-1;j>=0;j--)nw.push_back(Z[j]);
			for(auto x:F)nw.push_back(x);
			for(int j=i;j<Z.size();j++)nw.push_back(Z[j]);
			res=max(res,calc(A,nw));
		}
		for(int i=0;i<=Z.size();i++){
			vector<int> nw;
			for(int j=i-1;j>=0;j--)nw.push_back(Z[j]);
			for(auto x:F)nw.push_back(x);
			for(int j=((int)Z.size())-1;j>=i;j--)nw.push_back(Z[j]);
			res=max(res,calc(A,nw));
		}
		for(int i=0;i<=Z.size();i++){
			vector<int> nw;
			for(int j=0;j<i;j++)nw.push_back(Z[j]);
			for(auto x:F)nw.push_back(x);
			for(int j=((int)Z.size())-1;j>=i;j--)nw.push_back(Z[j]);
			res=max(res,calc(A,nw));
		}
	};
	CALC(Z,F);CALC(F,Z);
	reverse(Z.begin(),Z.end());
	CALC(Z,F);CALC(F,Z);
	reverse(F.begin(),F.end());
	CALC(Z,F);CALC(F,Z);
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}