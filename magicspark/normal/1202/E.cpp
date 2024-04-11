/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
const int magic=500;
int pre[200005],suf[200005];
struct Trie{
	int trie[1000005][26],size,vis[1000005];
	void init(){
		memset(trie,-1,sizeof(trie));
		memset(vis,0,sizeof(vis));
		size=1;
	}
	void insert(string s){
		int n=s.size(),cur=0;
		for(int i=0;i<n;i++){
			if(trie[cur][s[i]-'a']==-1){
				trie[cur][s[i]-'a']=size++;
			}
			cur=trie[cur][s[i]-'a'];
		}
	}
	void add(string s,int v=1){
		int n=s.size(),cur=0;
		for(int i=0;i<n;i++){
			if(trie[cur][s[i]-'a']==-1)trie[cur][s[i]-'a']=size++;
			cur=trie[cur][s[i]-'a'];
		}
		vis[cur]+=v;
	}
	void query(string &s,int st){
		int n=s.size(),cur=0;
		for(int i=st;i<n;i++){
			if(trie[cur][s[i]-'a']==-1)return;
			cur=trie[cur][s[i]-'a'];
//			cerr<<st<<" "<<i<<" "<<vis[cur]<<endl;
			pre[i]+=vis[cur];suf[st]+=vis[cur];
		}
		return;
	}
}Tree;
#define SZ 1000005
int len[SZ],fail[SZ];
void build(string &p){
	int len=p.size(),j=fail[0]=-1;
	for(int i=1;i<=len;i++){
		while(j>=0&&p[j]!=p[i-1])j=fail[j];
		fail[i]=++j;//if(p[fail[i]-1]==p[i-1])fail[i]=fail[fail[i]];
	}
}
bool kmp(string &_t,string &_s){
	int n=_t.size(),m=_s.size();
	for(int i=0,k=0;i<n;i++){
		while(k>=0&&_s[k]!=_t[i])k=fail[k];
		len[i]=++k;
		if(len[i]==m){
			pre[i]++;suf[i-m+1]++;
		}
	}
	return (*max_element(len,len+n))==m;
}
string S;
string t[200005];
int n;
signed main(){
	Tree.init();
	cin>>S;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		if(t[i].size()<=magic)Tree.add(t[i],1);
		else{
			build(t[i]);
			kmp(S,t[i]);
		}
	}
	for(int i=0;i<S.size();i++){
		Tree.query(S,i);
	}
	int ans=0;
	for(int i=1;i<S.size();i++){
//		cerr<<i<<" "<<pre[i-1]<<" "<<suf[i]<<endl;
		ans+=pre[i-1]*suf[i];
	}
	cout<<ans<<endl;
	return 0;
}