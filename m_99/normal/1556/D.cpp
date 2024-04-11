#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
vector<int> debug;
bool df = false;
int OR(int i,int j){
	cout<<"or "<<i+1<<' '<<j+1<<endl;
	if(df){
		return debug[i]|debug[j];
	}
	int ret;
	cin>>ret;
	return ret;
}

int AND(int i,int j){
	cout<<"and "<<i+1<<' '<<j+1<<endl;
	if(df){
		return debug[i]&debug[j];
	}
	int ret;
	cin>>ret;
	return ret;
}

void answer(int a){
	cout<<"finish "<<a<<endl;
}

int main(){
	
	int n,k;
	cin>>n>>k;
	if(df){
		debug.resize(n);
		rep(i,n)cin>>debug[i];
	}
	vector<int> A(n,0),B(n,0);
	for(int i=1;i<n;i++){
		A[i] = AND(0,i);
		B[i] = OR(0,i);
	}
	
	int temp = AND(1,2);
	vector<int> a(n,0);
	rep(i,30){
		bool f = false;
		for(int j=1;j<n;j++){
			int aa = (A[j]>>i)&1;
			int bb = (B[j]>>i)&1;
			if(aa&&bb){
				f = true;
				a[0] |= 1<<i;
				break;
			}
			if(!aa&&!bb){
				f = true;
				break;
			}
		}
		if(!f){
			if((temp>>i)&1){
			}
			else{
				a[0] |= 1<<i;
			}
		}
	}
	
	for(int i=1;i<n;i++){
		int XOR = A[i] ^ B[i];
		a[i] = XOR ^ a[0];
	}
	sort(a.begin(),a.end());
	answer(a[k-1]);
	
	
	
	return 0;
}