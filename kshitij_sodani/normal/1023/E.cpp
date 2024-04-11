#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int check(int ac,int bc,int cc,int dc){
	cout<<"?"<<" "<<ac<<" "<<bc<<" "<<cc<<" "<<dc<<endl;
	string s;
	cin>>s;
	if(s=="YES"){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int l=1;
	int r=1;
	vector<int> ans;
	for(int i=0;i<n-1;i++){
		if(check(l+1,r,n,n)){
			l+=1;
			ans.pb(1);
		}
		else{
			r+=1;
			ans.pb(0);
		}
	}
	l=n;
	r=n;
	vector<int> ans2;
	for(int i=0;i<n-1;i++){
		if(check(1,1,l,r-1)){
			r-=1;
			ans2.pb(0);
		}
		else{
			l-=1;
			ans2.pb(1);
		}
	}
	reverse(ans2.begin(),ans2.end());
	cout<<"! ";
	for(auto i:ans){
		if(i==1){
			cout<<"D";
		}
		else{
			cout<<"R";
		}
	}
	for(auto i:ans2){
		if(i==1){
			cout<<"D";
		}
		else{
			cout<<"R";
		}
	}
	cout<<endl;

	
	return 0;
}