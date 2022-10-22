#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int k;
	cin>>k;
	
	string s;
	cin>>s;
	
	vector<int> cnt(1<<(1+k),0);
	
	for(int i=(1<<k);i<cnt.size();i++)cnt[i] = 1;
	vector<int> pos;
	for(int i=k-1;i>=0;i--){
		rep(j,1<<i){
			pos.push_back((1<<i) + j);
		}
	}
	
	vector<int> inv(pos.size()+5);
	rep(i,pos.size()){
		inv[pos[i]] = i;
	}
	
	/*
	rep(i,pos.size()){
		cout<<pos[i]<<endl;
	}
	*/
	
	rep(i,s.size()){
		int t = pos[i];
		if(s[i]=='0')cnt[t] = cnt[t*2];
		if(s[i]=='1')cnt[t] = cnt[t*2+1];
		if(s[i]=='?')cnt[t] = cnt[t*2] + cnt[t*2+1];
	}
	
	int q;
	cin>>q;
	
	rep(_,q){
		int p;
		char c;
		scanf("%d %c",&p,&c);
		p--;
		s[p] = c;
		p = pos[p];
		
		//s[p] = c;
		int cur = p;
		while(cur!=0){
			int ind = inv[cur];
			if(s[ind]=='0')cnt[cur] = cnt[cur*2];
			if(s[ind]=='1')cnt[cur] = cnt[cur*2+1];
			if(s[ind]=='?')cnt[cur] = cnt[cur*2] + cnt[cur*2+1];
			cur >>= 1;
		}
		printf("%d\n",cnt[1]);
	}
	
	
	return 0;
}