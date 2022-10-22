#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

bool check(int c0,int c1,int cq){
	if(c0>c1+cq||c1>c0+cq)return false;
	return true;
}

int main(){

	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool f = true;
		int c0=0,c1=0,cq=0;
		for(int i=0;i<n;i++){
			if(i+k>=n)break;
			if(s[i]==s[i+k])continue;
			if(s[i]=='?')s[i] = s[i+k];
			else if(s[i+k]=='?')s[i+k] = s[i];
			else{
				f=false;
				break;
			}
		}
		
		if(!f){
			cout<<"NO"<<endl;
			continue;
		}
		
		rep(i,k){
			if(s[i]=='0')c0++;
			else if(s[i]=='1')c1++;
			else cq++;
		}
		if(!check(c0,c1,cq))f=false;
		for(int i=k;i<s.size();i++){
			if(s[i-k]=='0')c0--;
			else if(s[i-k]=='1')c1--;
			else cq--;
			if(s[i]=='0')c0++;
			else if(s[i]=='1')c1++;
			else cq++;
			if(!check(c0,c1,cq))f=false;
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
    
    return 0;
}