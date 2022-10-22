#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string x1;
		int p1;
		string x2;
		int p2;
		cin>>x1>>p1>>x2>>p2;
		int s1 = x1.size() + p1;
		int s2 = x2.size() + p2;
		if(s1<s2)cout<<"<"<<endl;
		else if(s2<s1)cout<<">"<<endl;
		else{
			while(x1.size()>x2.size())x2.push_back('0');
			while(x1.size()<x2.size())x1.push_back('0');
			if(x1<x2)cout<<"<"<<endl;
			else if(x1>x2)cout<<">"<<endl;
			else cout<<"="<<endl;
		}
		
	}
	
	
	return 0;
}