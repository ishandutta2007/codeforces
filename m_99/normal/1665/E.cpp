#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
using A = array<pair<int,int>,2>;

A op(A a,A b){
	A ret;
	ret[0] = max(a[0],b[0]);
	if(ret[0]==a[0]){
		ret[1] = max(a[1],b[0]);
	}
	else{
		ret[1] = max(a[0],b[1]);
	}
	return ret;
}

A e(){
	A ret;
	rep(i,2)ret[i] = make_pair(-1,0);
	return ret;
}

template <typename T>
struct trie{
	T init_value;
	struct node{
		vector<int> next;
		T v;
		int depth;
		node(int wordSize,T iv,int d){
			next.resize(wordSize,-1);
			v = iv;
			depth = d;
		}
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
		nodes[cNode].v = e();
		rep(i,2){
			if(nodes[cNode].next[i]!=-1)nodes[cNode].v = op(nodes[cNode].v, nodes[nodes[cNode].next[i]].v);
		}
	}
	
	
	int query(int L, int &ans, int d = 29, vector<int> vs = {},int cNode=0){
		if(d==-1)return 0;
		int cnt = 0;
		rep(i,vs.size()){
			if(((vs[i]>>d)&1)==0)cnt++;
		}
		if(cNode!=-1 && nodes[cNode].next[0]!=-1){
			rep(i,2){
				if(nodes[nodes[cNode].next[0]].v[i].first>=L)cnt++;
			}
		}
		if(cnt>=2){
			int nxt = -1;
			if(cNode!=-1)nxt = nodes[cNode].next[0];
			vector<int> nv;
			rep(i,vs.size()){
				if((vs[i]>>d)&1)continue;
				nv.push_back(vs[i]);
			}
			query(L,ans,d-1,nv,nxt);
		}
		else{
			int nxt = -1;
			if(cNode!=-1)nxt = nodes[cNode].next[1];
			ans |= 1<<d;
			if(cNode!=-1 && nodes[cNode].next[0]!=-1){
				rep(i,2){
					if(nodes[nodes[cNode].next[0]].v[i].first>=L){
						vs.push_back(nodes[nodes[cNode].next[0]].v[i].second);
					}
				}
			}
			query(L,ans,d-1,vs,nxt);
		}
		return 0;
	}
	
	int encode(char c){
		return c-'0';
	}
	
	T func(T a,T b){
		return op(a,b);
	}
	
};

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		trie<A> T(2,e());
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int q;
		scanf("%d",&q);
		vector<int> l(q),r(q);
		vector<vector<int>> qs(n);
		rep(i,q){
			scanf("%d %d",&l[i],&r[i]);
			l[i]--,r[i]--;
			qs[r[i]].push_back(i);
		}
		vector<int> ans(q);
		rep(i,n){
			string s = "";
			for(int j=29;j>=0;j--){
				if((a[i]>>j)&1)s += '1';
				else s += '0';
			}
			A temp = e();
			temp[0] = make_pair(i,a[i]);
			T.add(s,temp);
			rep(j,qs[i].size()){
				int ind = qs[i][j];
				T.query(l[ind], ans[ind]);
			}
		}
		rep(i,q){
			//if(i!=0)printf(" ");
			printf("%d\n",ans[i]);
		}
		//printf("\n");
	}
		
	return 0;
}