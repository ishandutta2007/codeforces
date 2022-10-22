#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

template <int sz = 30>
struct binary_trie{
	vector<array<int,2>> nxt;
	vector<int> cnt;
	
	long long lazy = 0LL;
	
	binary_trie(){
		cnt.resize(1,0);
		nxt.resize(1,{-1,-1});
	}
	
	int get(int cur,int b){
		if(nxt[cur][b]==-1){
			nxt[cur][b] = nxt.size();
			nxt.push_back({-1,-1});
			cnt.push_back(0);
		}
		return nxt[cur][b];
	}
	
	void calc(int cur){
		cnt[cur] = 0;
		rep(i,2){
			if(nxt[cur][i]==-1)continue;
			cnt[cur] += cnt[nxt[cur][i]];
		}
	}
	
	void add(long long x,int pos,int cur){
		if(pos<0){
			cnt[cur] ++;
			return;
		}
		int ncur = get(cur,(x>>pos)&1);
		add(x,pos-1,ncur);
		calc(cur);
	}
	
	void add(long long x){
		add(x^lazy,sz-1,0);
	}
	
	void del(long long x,int pos,int cur){
		if(pos<0){
			cnt[cur] --;
			return;
		}
		if(nxt[cur][(x>>pos)&1]==-1)return;
		int ncur = get(cur,(x>>pos)&1);
		del(x,pos-1,ncur);
		calc(cur);
	}
	
	void del(long long x){
		del(x^lazy,sz-1,0);
	}
	
	void all_apply(long long x){
		lazy ^= x;
	}
	
	int size(){
		return cnt[0];
	}
	
	int lower(long long x,int pos,int cur){
		if(pos<0)return cnt[cur];
		int ret = 0;
		int t = (x>>pos)&1;
		int l = (lazy>>pos)&1;
		if(t==0){
			if(nxt[cur][l^1]!=-1)ret += cnt[nxt[cur][l^1]];
		}
		if(nxt[cur][t^l]!=-1){
			ret += lower(x,pos-1,nxt[cur][t^l]);
		}
		return ret;		
	}
	//[x,Inf)
	int lower(long long x){
		if(x<0)return 0;
		if(x>=(1LL<<sz))return size();
		return lower(x,sz-1,0);
	}
	//(x,Inf)
	int upper(long long x){
		return lower(x+1,sz-1,0);
	}
	
	long long nth_element(int n,int pos,int cur){
		if(pos<0)return 0;
		long long l = (lazy >> pos)&1;
		long long ret = 0;
		rep(i,2){
			if(nxt[cur][l^i]==-1)continue;
			if(cnt[nxt[cur][l^i]] < n)n -= cnt[nxt[cur][l^i]];
			else{
				ret = (1LL<<pos) * i;
				return ret ^ nth_element(n,pos-1,nxt[cur][l^i]);
			}
		}
		return 0;
	}
	//nth largest element
	long long nth_element(int n){
		if(n>size())return -1;
		return nth_element(n,sz-1,0);
	}
	
};

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int l,r;
		scanf("%d %d",&l,&r);
		vector<int> a(r-l+1);
		binary_trie B;
		rep(i,a.size()){
			scanf("%d",&a[i]);
			B.add(a[i]);
		}
		//cout<<B.nth_element(r-l+1)<<endl;
		int x=  0;
		rep(i,a.size()){
			B.all_apply(a[i] ^ l);
			if(B.nth_element(r-l+1) == r && B.nth_element(1)==l){
				x = a[i]^l;
				break;
			}
			B.all_apply(a[i] ^ l);
		}
		cout<<x<<endl;
		
	}
	
	return 0;
}