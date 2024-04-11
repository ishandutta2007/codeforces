#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


struct trie{
	vector<trie*> next;
	bool flag;
	int cnt;
	trie(){
		next.resize(26,0);
		flag=false;
		cnt=0;
	}
	
	void add(string &s){
		trie* now = this;
		for(int i=0;i<s.size();i++){
			int c=s[i]-'a';
				
			if(now->next[c]==0){
				now->next[c] = new trie;
				now->next[c]->cnt = now->cnt+1;
			}
			now = now->next[c];
		}
		now->flag=true;
	}
	
	
	int check(string s){
		int ret = 0;
		trie* now = this;
		for(int i=0;i<s.size();i++){
			int c=s[i]-'A';
			if(now->next[c]==0){
				return ret;
			}
			now = now->next[c];
			if(now->flag)ret=i+1;
		}
		return ret;
	}
	
	priority_queue<int>* dfs(){
		priority_queue<int>* P = new priority_queue<int>;
		for(int i=0;i<26;i++){
			if(next[i]==0)continue;
			auto temp = next[i]->dfs();
			
			if(P->size()<temp->size())swap(P,temp);
			while(temp->size()!=0){
				P->push(temp->top());
				temp->pop();
			}
		}
		
		if(flag)P->push(cnt);
		else if(cnt!=0){
			P->pop();
			P->push(cnt);
		}
		return P;
	}
	
};

int main() {
	
	int n;
	cin>>n;
	
	trie T;
	
	vector<int> cnt(26,0);
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		T.add(s);
		cnt[s[0]-'a']++;
	}

	
	auto M = T.dfs();
	
	long long ans = 0;

	while(M->size()!=0){
		ans += M->top();
		M->pop();
	}
	
	cout<<ans<<endl;
	
    return 0;
}