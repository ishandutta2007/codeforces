#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool is_prime(string s){
	static map<string,bool> mp;
	if(mp.count(s))return mp[s];
	long long t = stoll(s);
	bool f = true;
	for(long long i=2;i*i<=t;i++){
		
		if(t%i==0){
			f = false;
			break;
		}
	}
	mp[s] = f;
	return f;
}

bool have(string s,string t){
	int cur = 0;
	rep(i,s.size()){
		if(cur!=t.size()&&s[i]==t[cur])cur++;
	}
	return cur==t.size();
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int k;
		cin>>k;
		string s;
		cin>>s;
		
		int ind = -1;
		rep(i,s.size()){
			if(s[i]=='1'||s[i]=='4'||s[i]=='6'||s[i]=='8'||s[i]=='9'){
				ind = i;
				break;
			}
		}
		if(ind!=-1){
			cout<<1<<endl;
			cout<<s[ind]<<endl;
			continue;
		}
		
		vector<string> cur = {"2","3","5","7"};
		
		for(int i=2;true;i++){
			vector<string> nxt;
			rep(j,cur.size()){
				nxt.push_back(cur[j]+'2');
				nxt.push_back(cur[j]+'3');
				nxt.push_back(cur[j]+'5');
				nxt.push_back(cur[j]+'7');
			}
			swap(cur,nxt);
			string ans = "";
			rep(j,nxt.size()){
				if(is_prime(nxt[j]))continue;
				if(have(s,nxt[j])){
					ans = nxt[j];
					break;
				}
			}
			if(ans!=""){
				cout<<ans.size()<<endl;
				cout<<ans<<endl;
				break;
			}
		}
		
		
	}
	
	return 0;
}