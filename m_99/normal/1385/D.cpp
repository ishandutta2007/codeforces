#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int get(string s,char c){
	if(s.size()==1){
		if(s[0]==c)return 0;
		return 1;
	}
	int n = s.size();
	string s0 = s.substr(0,n/2);
	string s1 = s.substr(n/2);
	
	int ret = Inf;
	{
		int temp = 0;
		rep(i,s0.size()){
			if(s0[i]!=c)temp++;
		}
		temp += get(s1,c+1);
		ret = min(ret,temp);
	}
	{
		int temp = 0;
		rep(i,s1.size()){
			if(s1[i]!=c)temp++;
		}
		temp += get(s0,c+1);
		ret = min(ret,temp);
	}
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		cout<<get(s,'a')<<endl;
		
	}
	
	return 0;
}