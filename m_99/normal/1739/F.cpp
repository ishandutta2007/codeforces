#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

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
		return c-'a';
	}
	
	T func(T a,T b){
		return a+b;
	}
	
};

int main(){
	
	int n;
	cin>>n;
	
	vector<int> c;
	vector<string> s;
	
	rep(i,n){
		int v;
		string t;
		cin>>v>>t;
		if(t.size()==1)continue;
		string cur = "";
		cur += t[0];
		bool F = true;
		for(int j=1;j<t.size();j++){
			bool f = false;
			rep(k,cur.size()-1){
				if(cur[k]==t[j]&&cur[k+1]==t[j-1]){
					f = true;
					break;
				}
				if(cur[k]==t[j-1]&&cur[k+1]==t[j]){
					f = true;
					break;
				}
			}
			if(f)continue;
			if(!f){
				if(cur.back()==t[j-1])cur += t[j];
				else if(cur[0]==t[j-1])cur.insert(cur.begin(),t[j]);
				else{
					F= false;
					break;
				}
			}
		}
		if(!F)continue;
		if(cur.size()==1)continue;
		auto cd = cur;
		sort(cd.begin(),cd.end());
		cd.erase(unique(cd.begin(),cd.end()),cd.end());
		if(cd.size()!=cur.size())continue;
		c.push_back(v);
		s.push_back(cur);
		reverse(cur.begin(),cur.end());
		c.push_back(v);
		s.push_back(cur);
	}
	
	trie<int> T(13,0);
	
	rep(i,c.size()){
		T.add(s[i],c[i]);
	}
	T.set_link();
	
	vector dp(T.nodes.size(),vector<int>(1<<13,-Inf32));
	dp[0][0] = 0;
	vector memo(T.nodes.size(),vector<string>(1<<13,""));
	
	rep(i,1<<13){
		rep(j,T.nodes.size()){
			if(dp[j][i]==-Inf32)continue;
			rep(k,13){
				if((i>>k)&1)continue;
				int nextNode = T.nodes[j].next[k];
				if(nextNode==-1){
					int nv = dp[j][i];
					int cur = j;
					while(cur != 0 && T.nodes[cur].next[k]==-1){
						cur = T.nodes[cur].link;
					}
					if(T.nodes[cur].next[k]==-1)nextNode = 0;
					else{
						nextNode = T.nodes[cur].next[k];
						nv += T.nodes[nextNode].v;
					}
					int nj = i | (1<<k);
					if(nv > dp[nextNode][nj]){
						dp[nextNode][nj] = nv;
						memo[nextNode][nj] = memo[j][i] + string(1,('a'+k));
					}
				}
				else{
					
					int nj = i | (1<<k);
					int nv = dp[j][i];
					nv += T.nodes[nextNode].v;
					if(nv > dp[nextNode][nj]){
						dp[nextNode][nj] = nv;
						memo[nextNode][nj] = memo[j][i] + string(1,('a'+k));
					}
				}
				
			}
		}
	}
	
	int ans = -1;
	string ss = "";
	rep(i,T.nodes.size()){
		if(dp[i].back()>ans){
			ans = dp[i].back();
			ss = memo[i].back();
		}
	}
	
	rep(i,ss.size()){
		if(ss[i]=='m'){
			ss.erase(ss.begin()+i);
			break;
		}
	}
	
	cout<<ss<<endl;
	
	return 0;
}