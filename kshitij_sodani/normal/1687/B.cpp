#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back

llo n,m;
llo query(vector<llo> tt){
	cout<<"? ";
	for(auto j:tt){
		cout<<j;
	}
	cout<<endl;
	llo x;
	cin>>x;
	return x;
}
llo it[501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	vector<llo> aa;
	for(llo i=0;i<m;i++){
		aa.pb(0);
	}
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<m;i++){
		aa[i]=1;
		it[i]=query(aa);
		aa[i]=0;
		ss.pb({it[i],i});
	}
	sort(ss.begin(),ss.end());
	llo cur=0;
	llo cur2=0;
	for(auto j:ss){
		aa[j.b]=1;
		llo x=query(aa);
		if(x==cur2+j.a){
			//x must in spanning tree
			cur2=x;
		}
		else{
			aa[j.b]=0;
		}
		/*if(x>cur){
			cur=x;
		}
		else{
			aa[j.b]=0;
		}*/
	}
	cout<<"! "<<cur2<<endl;





	return 0;
}