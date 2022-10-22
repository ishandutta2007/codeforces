#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

string get(long long x){
	string ret = "";
	while(x!=0){
		ret += (x&1) + '0';
		x /= 2;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
void ok(){
	cout<<"YES"<<endl;
	exit(0);
}

void check(string X,string Y){
	rep(i,100){
		rep(j,100){
			string a(i,'1'),b(j,'1');
			if(a + X + b == Y){
				ok();
			}
		}
	}
	reverse(X.begin(),X.end());
	rep(i,100){
		rep(j,100){
			string a(i,'1'),b(j,'1');
			if(a + X + b == Y){
				ok();
			}
		}
	}
}

int main(){
	
	long long x,y;
	cin>>x>>y;
	if(x==y){
		ok();
	}
	string X = get(x),Y = get(y);
	
	if(X.back()=='0'){
		string t = X;
		while(t.back()=='0')t.pop_back();
		check(t,Y);
		t = X;
		t += '1';
		check(t,Y);
		
	}
	else{
		check(X,Y);
	}
	
	cout<<"NO"<<endl;
	
	
	return 0;
}