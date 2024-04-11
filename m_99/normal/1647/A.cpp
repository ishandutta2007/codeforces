#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
pair<string,bool> get(int n,char c){
	string ret(1,c);
	n -= c - '0';
	int last = c - '0';
	while(n>0){
		if(last==1)last = 2;
		else last = 1;
		ret += '0' + last;
		n -= last;
	}
	if(n<0)return make_pair(ret,false);
	else return make_pair(ret,true);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		
		int n;
		cin>>n;
		auto r0 = get(n,'2');
		if(r0.second==false)r0 = get(n,'1');
		cout<<r0.first<<endl;
		
		
	}
	
	return 0;
}