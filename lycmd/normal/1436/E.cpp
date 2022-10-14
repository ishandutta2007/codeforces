#include<bits/stdc++.h>
using namespace std;
int const N=233333,B=616;
int n,a[N],tr[N],pre[N],cnt[N],ans[N];
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		if(l/B!=rhs.l/B)
			return l/B<rhs.l/B;
		return l/B%2?r<rhs.r:r>rhs.r;
	}
};
vector<query>p;
namespace mybitset{
	typedef unsigned long long ull;
	inline int popcnt(ull x){
		return x?popcnt(x&(x-1))+1:0;
	}
	struct mybitset{
		static int const B=63,K=6;
		int sz;
		vector<ull>s;
		mybitset(){
			s.clear(),sz=0;
		};
		mybitset(ull x){
			s.clear(),s.push_back(x),sz=1;
		}
		void init(int n){
			s.clear();s.resize((n>>K)+1),sz=s.size();
		}
		int size(){
			return sz<<K;
		} 
		void reset(){
			s.clear(),s.resize(sz,0);
		}
		void set(){
			s.clear(),s.resize(sz,~0);
		}
		void flip(){
			for(int i=0;i<sz;i++)
				s[i]=~s[i];
		}
		void set1(int p){
			s[p>>K]|=1ull<<(p&B);
		}
		void set0(int p){
			s[p>>K]&=~(1ull<<(p&B));
		}
		void flip(int p){
			s[p>>K]^=1ull<<(p&B);
		}
		int any(){
			for(int i=0;i<sz;i++)
				if(s[i])
					return 1;
			return 0;
		}
		int none(){
			for(int i=0;i<sz;i++)
				if(s[i])
					return 0;
			return 1;
		}
		int all(){
			for(int i=0;i<sz;i++)
				if(~s[i])
					return 0;
			return 1;
		}
		int getbit(int p){
			return (s[p>>K]>>(p&B))&1;
		}
		int mex(){
			for(int i=0;i<sz;i++)
				if(~s[i])
					for(int j=0;j<=B;j++)
						if((~s[i]>>j)&1)
							return i<<K|j;
			return -1;
		}
		string tostring(){
			string ans="";
			for(int i=0;i<sz;i++)
				for(int j=0;j<=B;j++)
					ans+=48|((s[i]>>j)&1);
			reverse(ans.begin(),ans.end());
			return ans;
		}
		mybitset operator~()const{
			mybitset ans;ans.init(sz<<K);
			for(int i=0;i<sz;i++)
				ans.s.push_back(~s[i]);
			return ans;
		}
		mybitset operator&(const mybitset&rhs)const{
			mybitset ans;
			ans.init(sz<<K);
			for(int i=0;i<ans.sz;i++)
				ans.s[i]=s[i]&rhs.s[i];
			return ans;
		}
		mybitset operator|(const mybitset&rhs)const{
			mybitset ans;
			ans.init(sz<<K);
			for(int i=0;i<ans.sz;i++)
				ans.s[i]=s[i]|rhs.s[i];
			return ans;
		}
		mybitset operator^(const mybitset&rhs)const{
			mybitset ans;
			ans.init(sz<<K);
			for(int i=0;i<ans.sz;i++)
				ans.s[i]=s[i]^rhs.s[i];
			return ans;
		}
		mybitset operator<<(int p)const{
			mybitset ans;
			ans.init(sz<<K);
			int x=p>>K,y=p&B;
			if(y){
				for(int i=sz-1;i>x;i--)
					ans.s[i]=(s[i-x]<<y)|(s[i-x-1]>>(B-y+1));
			}else{
				for(int i=sz-1;i>x;i--)
					ans.s[i]=s[i-x];
			}
			ans.s[x]=s[0]<<y;
			return ans;
		}
		mybitset operator>>(int p)const{
			mybitset ans;
			ans.init(sz<<K);
			int x=p>>K,y=p&B;
			if(y){
				for(int i=0;i<sz-x-1;i++)
					ans.s[i]=(s[i+x]>>y)|(s[i+x+1]<<(B-y+1));
			}else{
				for(int i=0;i<sz-x-1;i++)
					ans.s[i]=s[i+x];
			}
			ans.s[sz-x-1]=s[sz-1]>>y;
			return ans;
		}
		mybitset&operator&=(const mybitset&rhs){
			for(int i=0;i<sz;i++)
				s[i]&=rhs.s[i];
			return*this;
		}
		mybitset&operator|=(const mybitset&rhs){
			for(int i=0;i<sz;i++)
				s[i]|=rhs.s[i];
			return*this;
		}
		mybitset&operator^=(const mybitset&rhs){
			for(int i=0;i<sz;i++)
				s[i]^=rhs.s[i];
			return*this;
		}
		mybitset&operator<<=(int p){
			int x=p>>K,y=p&B;
			if(y){
				for(int i=sz-1;i>x;i--)
					s[i]=(s[i-x]<<y)|(s[i-x-1]>>(B-y+1));
			}else{
				for(int i=sz-1;i>x;i--)
					s[i]=s[i-x];
			}
			s[x]=s[0]<<y;
			for(int i=0;i<x;i++)
				s[i]=0;
			return*this;
		}
		mybitset&operator>>=(int p){
			int x=p>>K,y=p&B;
			if(y){
				for(int i=0;i<sz-x-1;i++)
					s[i]=(s[i+x]>>y)|(s[i+x+1]<<(B-y+1));
			}else{
				for(int i=0;i<sz-x-1;i++)
					s[i]=s[i+x];
			}
			s[sz-x-1]=s[sz-1]>>y;
			for(int i=sz-x;i<sz;i++)
				s[i]=0;
			return*this;
		}
		bool operator==(const mybitset&rhs)const{
			for(int i=0;i<sz;i++)
				if(s[i]^rhs.s[i])
					return 0;
			return 1;
		}
		bool operator!=(const mybitset&rhs)const{
			for(int i=0;i<sz;i++)
				if(s[i]^rhs.s[i])
					return 1;
			return 0;
		}
		int count(){
			int ans=0;
			for(int i=0;i<sz;i++)
				ans+=popcnt(s[i]);
			return ans;
		}
	};
}
mybitset::mybitset s;
void add(int x){
	if(!cnt[a[x]]++)
		s.set1(a[x]);
}
void del(int x){
	if(!--cnt[a[x]])
		s.set0(a[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push_back({pre[a[i]]+1,i-1,a[i]});
		pre[a[i]]=i;
	}
	for(int i=1;i<=n+2;i++)
		p.push_back({pre[i]+1,n,i});
	sort(p.begin(),p.end());
	int l=1,r=0;
	s.init(n+2),s.set1(0);
	for(int i=0;i<p.size();i++){
		if(ans[p[i].id]||p[i].l>p[i].r)
			continue;
		while(l<p[i].l)del(l++);
		while(l>p[i].l)add(--l);
		while(r<p[i].r)add(++r);
		while(r>p[i].r)del(r--);
		ans[p[i].id]=s.mex()==p[i].id;
	}
	for(int i=1;i<=n+2;i++)
		if(!ans[i])
			cout<<i<<"\n",exit(0);
}