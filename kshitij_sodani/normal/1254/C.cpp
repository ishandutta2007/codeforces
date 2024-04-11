//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo n;

bool clock(llo i,llo j,llo k){
	cout<<2<<" "<<i<<" "<<j<<" "<<k<<endl;
	llo x;
	cin>>x;
	return (x==-1);
}
llo area(llo i,llo j,llo k){
	cout<<1<<" "<<i<<" "<<j<<" "<<k<<endl;
	llo x;
	cin>>x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo cur=2;
	for(llo i=3;i<=n;i++){
		if(clock(1,i,cur)){
			cur=i;
		}
	}
	vector<pair<llo,llo>> ss;
	for(llo i=2;i<=n;i++){
		if(i!=cur){
			ss.pb({area(1,cur,i),i});
		}
	}
	sort(ss.begin(),ss.end());
	vector<llo> ans;
	llo cot=ss.back().b;
	ss.pop_back();
	vector<llo> aa;

	vector<llo> bb;
	while(ss.size()){
		llo no=ss.back().b;
		if(clock(1,no,cot)){
			aa.pb(no);
		}
		else{
			bb.pb(no);
		}
		ss.pop_back();
	}
	ans.pb(1);
	ans.pb(cur);
	while(aa.size()){
		ans.pb(aa.back());
		aa.pop_back();
	}
	ans.pb(cot);
	for(auto j:bb){
		ans.pb(j);
	}
	cout<<"0 1 ";
	for(llo i=ans.size()-1;i>=1;i--){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	/*for(llo i=ss.size()-1;i>=0;i--){

	}*/








 
	return 0;
}