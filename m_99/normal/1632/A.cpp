#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		vector cnt(2,0);
		rep(i,s.size())cnt[s[i]-'0']++;
		
		if(cnt[0]<=1&&cnt[1]<=1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}