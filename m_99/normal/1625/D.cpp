#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
vector<int> ok;

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

void dfs(vector<pair<int,int>> a,int k,int cur){
	if(a.size()==0)return;
	if(cur<0){
		rep(i,a.size()){
			ok.push_back(a[i].second);
		}
		return;
	}
	if((k>>cur)&1){
		vector<pair<int,int>> x,y;
		rep(i,a.size()){
			if((a[i].first>>cur)&1){
				x.push_back(a[i]);
			}
			else{
				y.push_back(a[i]);
			}
		}
		if(x.size()==0){
			ok.push_back(y[0].second);
		}
		else if(y.size()==0){
			ok.push_back(x[0].second);
		}
		else{
			rep(i,x.size()){
				x[i].first &= (1<<cur)-1;
			}
			rep(i,y.size()){
				y[i].first &= (1<<cur)-1;
			}
			k &= (1<<cur)-1;
				
			binary_trie B;
			rep(i,x.size()){
				B.add(x[i].first);
			}
			bool F = false;
			rep(i,y.size()){
				B.all_apply(y[i].first);
				int t = B.nth_element(x.size());
				
				if(t>=k){
					ok.push_back(y[i].second);
					t ^= y[i].first;
					rep(j,x.size()){
						if(x[j].first == t){
							ok.push_back(x[j].second);
							F = true;
							break;
						}
					}
					break;
				}
				B.all_apply(y[i].first);
			}
			if(!F)ok.push_back(x[0].second);
			
			
			
		}
	}
	else{
		vector<pair<int,int>> x,y;
		rep(i,a.size()){
			if((a[i].first>>cur)&1){
				x.push_back(a[i]);
			}
			else{
				y.push_back(a[i]);
			}
		}
		dfs(x,k,cur-1);
		dfs(y,k,cur-1);
	}
}

int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<pair<int,int>> a(n);
	rep(i,n){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	
	dfs(a,k,29);
	sort(ok.begin(),ok.end());
	ok.erase(unique(ok.begin(),ok.end()),ok.end());
	if(ok.size()<=1)cout<<-1<<endl;
	else{
		cout<<ok.size()<<endl;
		rep(i,ok.size()){
			if(i!=0)printf(" ");
			printf("%d",ok[i]+1);
		}
		cout<<endl;
	}
	
	
	return 0;
}