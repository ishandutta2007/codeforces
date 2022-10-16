#include<bits/stdc++.h>
using namespace std;
int cnt[3][3];
map<char,int>to;
string print="BGR";
string tmp="BGR";
string s;
int calc(){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		cnt+=(s[i]!=tmp[i%3]);
	}
	return cnt;
}
int main(){
	int ans;cin>>ans;cin>>s;
	do{
		//cout<<tmp<<" "<<calc()<<endl;
		int T=calc();
		if(T<ans){
			ans=T;
			print=tmp;
		}
	}while(next_permutation(tmp.begin(),tmp.end()));
	cout<<ans<<endl;
	for(int i=0;i<s.size();i++)cout<<print[i%3];
}