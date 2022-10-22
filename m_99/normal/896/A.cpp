#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000001

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fa = "What are you doing while sending \"";
string fb = "\"? Are you busy? Will you send \"";
string fc = "\"?";
vector<long long> sz(100001,0);

char dfs(long long n,long long k){
	if(n==0){
		return f0[k-1];
	}
	if(k<=fa.size()){
		return fa[k-1];
	}
	k-=fa.size();
	if(k<=sz[n-1])return dfs(n-1,k);
	k-=sz[n-1];
	if(k<=fb.size()){
		return fb[k-1];
	}
	k-=fb.size();
	if(k<=sz[n-1])return dfs(n-1,k);
	k-=sz[n-1];
	return fc[k-1];
}

int main(){
	
	sz[0] = f0.size();
	for(int i=1;i<sz.size();i++){
		sz[i] = min(Inf,sz[i-1]*2 + ((long long)(fa.size()+fb.size()+fc.size())));
	}
	
	int q;
	cin>>q;
	string ans  ="";
	for(int _=0;_<q;_++){
		long long n,k;
		cin>>n>>k;
		
		if(sz[n]<k){
			ans+='.';
			continue;
		}
		
		ans+=dfs(n,k);
	}
	cout<<ans<<endl;
	
	return 0;
}