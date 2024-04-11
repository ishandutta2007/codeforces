#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[200001];
multiset<llo> cur;
llo solve(llo su){
	if(cur.find(su)!=cur.end()){
		auto j=cur.find(su);
		cur.erase(j);
		return 1;
	}
	if(su==1){
		return 0;
	}
	llo y=solve((su+1)/2);
	if(y==0){
		return 0;
	}
	llo x=solve(su/2);
	
	return min(x,y);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		cur.clear();
		llo su=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
			cur.insert(it[i]);
		}
		llo x=solve(su);
		if(x==1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
 
	}
 
 
 
 
	return 0;
}