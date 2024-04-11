#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

struct Data{
	long long cnt = 0;
	string S;
};

Data op(Data a,Data b){
	Data c;
	c.cnt = a.cnt + b.cnt;
	string temp = a.S + b.S;
	
	rep(i,a.S.size()){
		if(i+4>a.S.size()){
			if(temp.substr(i,4)=="haha")c.cnt ++;
		}
	}
	
	while(temp.size() >= 9){
		temp.erase(temp.begin() + 4);
	}
	
	c.S = temp;
	
	return c;
	
}
	

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		string last;
		map<string,Data> mp;
		rep(i,n){
			string x,y,z;
			cin>>x>>y>>z;
			last = x;
			if(y==":="){
				Data temp;
				temp.S = z;
				rep(j,z.size()){
					if(z.substr(j,4)=="haha"){
						temp.cnt++;
					}
				}
				mp[x] = temp;
			}
			else{
				cin>>y;
				string t;
				cin>>t;
				Data temp = op(mp[z],mp[t]);//mp[z] + mp[t];
				mp[x] = temp;
			}
		}
		/*
		for(auto a:mp){
			cout<<a.first<<','<<a.second.S<<','<<a.second.cnt<<endl;
		}*/
		
		cout<<mp[last].cnt<<endl;
			
	}
	return 0;
}