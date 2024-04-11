#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

void go(vector<int> a,vector<int> &ans,int d){
	if(a.size()==0)return;
	int m = 0;
	int ind = 0;
	rep(i,a.size()){
		if(m<a[i]){
			ind = i;
			m = a[i];
		}
	}
	ans[m-1] = d;
	vector<int> l(a.begin(),a.begin()+ind),r(a.begin()+ind+1,a.end());
	go(l,ans,d+1);
	go(r,ans,d+1);
}

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
		}
		
		vector<int> depth(n);
		
		go(a,depth,0);
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<depth[a[i]-1];
		}
		cout<<endl;
		
	}
	
    return 0;
}