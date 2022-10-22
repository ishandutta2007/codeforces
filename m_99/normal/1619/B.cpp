#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	vector<int> t;
	for(int i=1;i*i<=Inf;i++){
		t.push_back(i*i);
	}
	for(int i=1;i*i*i<=Inf;i++){
		t.push_back(i*i*i);
	}
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int n;
		cin>>n;
		
		cout<<distance(t.begin(),upper_bound(t.begin(),t.end(),n))<<endl;
	}
	return 0;
}