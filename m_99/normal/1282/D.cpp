#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int ret;

int main(){
	
	cout<<"a"<<endl;
	cin>>ret;
	if(ret==0)return 0;
	int sz = ret+1;
	if(sz>300){
		cout<<string(sz-1,'b')<<endl;
		cin>>ret;
		return 0;
	}
	string s(sz,'a');
	cout<<s<<endl;
	cin>>ret;
	if(ret==0)return 0;
	if(ret==sz){
		cout<<string(sz-1,'b')<<endl;
		cin>>ret;
		return 0;
	}
	int base = ret;
	string ans(sz,'a');
	
	for(int i=1;i<sz;i++){
		s[i] = 'b';
		cout<<s<<endl;
		cin>>ret;
		if(ret==0){
			return 0;
		}
		if(ret<base){
			ans[i] = 'b';
		}
		s[i] = 'a';
	}
	
	for(int i=1;i<sz;i++){
		if(s[i]!=ans[i])base--;
	}
	if(base==1){
		ans[0] = 'b';
	}
	
	cout<<ans<<endl;
	cin>>ret;
	
    return 0;
}