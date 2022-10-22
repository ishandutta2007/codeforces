#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		string a,s;
		cin>>a>>s;
		
		reverse(a.begin(),a.end());
		reverse(s.begin(),s.end());
		int x = 0,y = 0;
		string b = "";
		string ss = "";
		rep(i,a.size()){
			if(ss.size() >= s.size()){
				b = "-1";
				break;
			}
			int X = a[i]-'0';
			int Y = s[ss.size()]-'0';
			if(Y>=X){
				b += '0' + (Y-X);
				ss += s[ss.size()];
			}
			else{
				b += '0' + (10+Y-X);
				ss += s[ss.size()];
				ss += '1';
			}
			
		}
		while(s.size()>ss.size()){
			ss += s[ss.size()];
			b += ss.back();
		}
		if(s!=ss)b = "-1";
		if(b=="-1")cout<<b<<endl;
		else{
			reverse(b.begin(),b.end());
			cout<<stoll(b)<<endl;
		}
	}
	return 0;
}