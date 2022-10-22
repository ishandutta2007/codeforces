#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

template <int sz = 30>
struct binary_trie{
	vector<array<int,2>> nxt;
	vector<array<int,2>> val;
	long long lazy = 0LL;
	
	binary_trie(){
		nxt.resize(1,{-1,-1});
		array<int,2> t;
		rep(i,2)t[i] = 0;
		val.resize(1,t);
	}
	
	int findmax(long long x,int y,int cd = 29,int cp = 0){
		if(cd<0)return 0;
		int ret = 0;
		int t = (x>>cd)&1;
		int nn = nxt[cp][t^1];
		if(nn!=-1){
			int tt = t;
			tt  ^= 1;
			tt ^= (y>>cd)&1;
			ret = max(ret,val[nn][tt]);
		}
		nn = nxt[cp][t];
		if(nn!=-1)ret = max(ret,findmax(x,y,cd-1,nn));
		return ret;
	}
	
	int get(int cur,int b){
		if(nxt[cur][b]==-1){
			nxt[cur][b] = nxt.size();
			nxt.push_back({-1,-1});
			array<int,2> t;
			rep(j,2)t[j] = 0;
			val.push_back(t);
		}
		return nxt[cur][b];
	}
	
	void add(long long x,int y,int v,int pos,int cur){
		if(pos<0){
			return;
		}
		
		
		int ncur = get(cur,(x>>pos)&1);
		val[ncur][(y>>pos)&1] = max(val[ncur][(y>>pos)&1],v);
		add(x,y,v,pos-1,ncur);
	}
	
	void add(long long x,int y,int v){
		add(x^lazy,y,v,sz-1,0);
	}
	

	
	
	
};

int main() {	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int ans = 0;
		
		binary_trie<30> B;
		rep(i,n){
			int S = a[i] ^ i;
			int v = B.findmax(S,i);;
			
			v++;
			ans = max(ans,v);
			B.add(S,i,v);
		}
		
		
		cout<<ans<<endl;
	}
	
    return 0;
}