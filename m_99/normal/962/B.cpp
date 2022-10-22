#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	

	int n,a,b;
	cin>>n>>a>>b;
	
	string s;
	cin>>s;
	
	vector<int> cnt(n,0);
	
	rep(i,n){
		if(s[i]=='*')continue;
		cnt[i] = 1;
		if(i!=0)cnt[i] += cnt[i-1];
	}
	
	vector<int> x;
	
	rep(i,n){
		if(i==n-1){
			x.push_back(cnt[i]);
		}
		else{
			if(cnt[i+1]==0){
				x.push_back(cnt[i]);
			}
		}
	}
	cnt = x;
	int A=a,B=b;
	
	rep(i,cnt.size()){
		A -= cnt[i]/2;
		B -= cnt[i]/2;
		if(cnt[i]%2==1){
			if(A>B)A--;
			else B--;
		}
	}
		
	
	A = max(A,0);
	B = max(B,0);
	
	
	
	cout<<(a-A) + (b-B)<<endl;
	
    return 0;
}