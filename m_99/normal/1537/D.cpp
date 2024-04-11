#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool get(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			if(!get(n-i))return true;
		}
	}
	return false;
}

int main(){
	/*
	for(int i=1;i<=100;i++){
		cout<<i<<','<<get(i)<<endl;
	}*/
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		bool f;
		if(n%2==1)f = false;
		else{
			f = true;
			for(int i=1;i<=30;i+=2){
				if(n==(1<<i))f = false;
			}
		}
		
		if(f)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
			
		
	}
	
	return 0;
}