#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

string trans(string S){
	int X = S.size()/2;
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='(')X--;
	}
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='?'){
			if(X<=0){
				S[i]=')';
			}
			else{
				X--;
				S[i]='(';
			}
		}
	}
	return S;
}

bool correct(string S){
	int x = 0;
	for(int i=0;i<S.size();i++){
		if(S[i]=='?')return false;
		if(S[i]=='(')x++;
		else x--;
		if(x<0)return false;
	}
	return (x==0);
}

int main() {
	
	int n;
	cin>>n;
	
	string S;
	cin>>S;
	
	if(S.size()==1){
		cout<<":("<<endl;
		return 0;
	}
	
	if(S[0]=='?')S[0] = '(';
	if(S.back()=='?')S.back()=')';
	
	string a = S.substr(0,1);
	string b = S.substr(S.size()-1);
	string c = S.substr(1,S.size()-2);
	
	c = trans(c);
	if(!correct(c)){
		cout<<":("<<endl;
		return 0;
	}
	
	string ans = a + c + b;
	
	if(correct(ans))cout<<ans<<endl;
	else cout<<":("<<endl;
	
    return 0;
}