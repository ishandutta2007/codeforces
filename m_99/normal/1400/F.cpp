#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

template <typename T>
struct trie{
	T init_value;
	struct node{
		vector<int> next;
		T v;
		T sum;
		int depth;
		node(int wordSize,T iv,int d){
			next.resize(wordSize,-1);
			v = iv;
			sum = iv;
			depth = d;
		}
		
		int link=-1;
	};
	vector<node> nodes;

	int wordSize;
	trie(int sz,T iv){
		init_value = iv;
		wordSize = sz;
		nodes.push_back(node(wordSize,init_value,0));
	}
	
	void add(string &S,T x,int cPos=0,int cNode=0){
		if(cPos==S.size()){
			nodes[cNode].v = func(nodes[cNode].v,x);
			return;
		}
		int c = encode(S[cPos]);
		if(nodes[cNode].next[c]==-1){
			nodes[cNode].next[c] = nodes.size();
			nodes.push_back(node(wordSize,init_value,nodes[cNode].depth+1));
		}
		
		int nextNode = nodes[cNode].next[c];
		add(S,x,cPos+1,nextNode);
	}
	
	void set_link(){
		nodes[0].link = 0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()!=0){
			int now = Q.front();
			Q.pop();
			nodes[now].v = func(nodes[now].v,nodes[nodes[now].link].v);
			nodes[now].sum = func(nodes[now].sum,nodes[now].v);
			for(int i=0;i<wordSize;i++){
				int to = nodes[now].next[i];
				if(to==-1)continue;
				int x = now;
				while(x!=0){
					x = nodes[x].link;
					if(nodes[x].next[i]!=-1){
						x = nodes[x].next[i];
						break;
					}
				}
				nodes[to].link = x;
				nodes[to].sum = func(nodes[to].sum,nodes[now].sum);
				Q.push(to);
			}
		}
	}
	
	T query(string &S,int cPos = 0,int cNode=0){
		T ret = init_value;
		if(cPos==S.size())return ret;
		int c = encode(S[cPos]);
		
		int nextNode = nodes[cNode].next[c];
		if(nextNode==-1){
			if(nodes[cNode].link!=-1){
				if(cNode!=0)ret = func(ret,query(S,cPos,nodes[cNode].link));
				else ret = func(ret,query(S,cPos+1,cNode));
			}
		}
		else{
			ret = func(ret,nodes[nextNode].v);
			ret = func(ret,query(S,cPos+1,nextNode));
		}
		
		return ret;
		
	}
	
	int encode(char c){
		return c-'1';
	}
	
	T func(T a,T b){
		return a+b;
	}
	
};

int main(){
	
	string S;
	cin>>S;
	
	int x;
	cin>>x;
	
	trie<int> T(9,0);
	
	for(int i=0;i<(1<<(x-1));i++){
		vector<int> t(1,1);
		for(int j=0;j<x-1;j++){
			if((i>>j)&1)t.push_back(1);
			else t.back()++;
		}
		
		string s = "";
		for(int j=0;j<t.size();j++){
			if(t[j]>=10){
				s="";
				break;
			}
			s += t[j]+'0';
		}
		if(s=="")continue;
		int c = 0;
		for(int j=0;j<t.size();j++){
			int sum = 0;
			for(int k=j;k<t.size();k++){
				sum += t[k];
				if(x%sum==0)c++;
			}
		}
		if(c==1){
			T.add(s,1);
		}

	}
	
	T.set_link();
	
	vector<int> dp(T.nodes.size(),Inf);
	dp[0] = 0;
	
	for(int i=0;i<S.size();i++){
		vector<int> ndp(T.nodes.size(),Inf);
		
		for(int j=0;j<dp.size();j++){
			if(dp[j]==Inf)continue;
			ndp[j] = min(ndp[j],dp[j]+1);
			int c = T.encode(S[i]);
			int now = j;
			while(now!=0&&T.nodes[now].next[c]==-1){
				now = T.nodes[now].link;
			}
			int nxt = T.nodes[now].next[c];
			if(nxt==-1)nxt=0;
			ndp[nxt] = min(ndp[nxt],dp[j]);
		}
		for(int j=0;j<ndp.size();j++){
			if(T.nodes[j].v)ndp[j] = Inf;
		}
		swap(dp,ndp);
	}
	
	int ans = Inf;
	for(int i=0;i<dp.size();i++)ans = min(ans,dp[i]);
	
	cout<<ans<<endl;
	
	return 0;
}