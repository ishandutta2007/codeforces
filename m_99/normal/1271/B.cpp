#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	int n;
	cin>>n;
	string S;
	cin>>S;
	int B = 0;
	int W = 0;
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='B')B++;
		else W++;
	}
	char x;
	if(W%2==0){
		x = 'B';
	}
	else if(B%2==0){
		x = 'W';
	}
	else{
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> ans;
	
	for(int i=0;i<S.size()-1;i++){
		if(S[i]!=x){
			ans.push_back(i+1);
			if(S[i+1]=='B')S[i+1]='W';
			else S[i+1]='B';
		}
	}
	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	return 0;
}