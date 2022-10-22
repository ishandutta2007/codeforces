#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string t = "";
		cin>>t;
		string s = "";
		while(t.size()!=0){
			if(t.back()=='0'){
				t.pop_back();
				int x = t.back()-'0';
				t.pop_back();
				x += (t.back()-'0')*10;
				t.pop_back();
				s += 'a' + (x-1);
			}
			else{
				int x = t.back()-'0';
				t.pop_back();
				s += 'a' + (x-1);
			}
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	
	return 0;
}