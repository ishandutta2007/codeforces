#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

long long x;
bool f;

void go(long long a,long long b){
	if(a<b)swap(a,b);
	if(a==0||b==0)return;
	if(a<x)return;
	if(a%b==x%b){
		f = true;
		return;
	}
	a %= b;
	go(a,b);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long a,b;
		cin>>a>>b>>x;
		f = false;
		go(a,b);
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}