//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
#pragma optimize("Ofast")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
namespace fastio{
	char in[100000];
	int itr=0,llen=0;
	char get(){
		if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
		if(llen==0)return EOF;
		return in[itr++];
	}
	char out[100000];
	int itr2=0;
	void put(char c){
		out[itr2++]=c;
		if(itr2==100000){
			fwrite(out,1,100000,stdout);
			itr2=0;
		}
	}
	int clear(){
		fwrite(out,1,itr2,stdout);
		itr2=0;
		return 0;
	}
	int getint(){
    	int r=0; bool ng=0; char c; c=get();
    	while (c!='-'&&(c<'0'||c>'9')) c=get();
   		if (c=='-') ng=1, c=get();
    	while (c>='0'&&c<='9') r=r*10+c-'0', c=get();
    	return ng?inf:r;
	}
	string getstr(){
		string ret="";
		char ch=get();
		while(ch==' '||ch=='\n')ch=get();
		while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
		return ret;
	}
	void putstr(string s){
		for(int i=0;i<s.size();i++)put(s[i]);
	}
	void putint(int x){
		if(x==0){
			put('0');
			return;
		}
		char c[20];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
	void getarr(int arrname[],int size){
		 for(int i=0;i<size;i++)arrname[i]=getint();
	}
}
using namespace fastio;
#define fastio
int n,m;
int used[111111*5];
vector<int>g[111111*5];
vector<pair<int,int> >edges;
vector<int>ans;
void dfs(int x){
	used[x]=1;
	for(auto p:g[x]){
		if(used[p]==1){
			puts("-1");
			exit(0);
		}
		if(used[p]==0)dfs(p);
	}
	used[x]=2;
	ans.push_back(x);
}
int main(){
	n=getint();m=getint();
	vector<vector<int> >vec(n,vector<int>(m));
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)vec[i][j]=getint();
	int pre=m;
	for(int i=0;i<n;i++){
		bool buff=(i==0);
		vector<pair<int,int> >V;
		for(int j=0;j<m;j++)V.push_back(make_pair(vec[i][j],j));
		sort(V.begin(),V.end());
		while(V.back().first==inf)V.pop_back();
		if(!V.size())continue;
		int pos=0;
		set<int>Set;
		Set.clear();
		for(int ii=0;ii<V.size();ii++){
			Set.insert(V[ii].first);
		}
		bool first=true;
		for(set<int>::iterator itr=Set.begin();itr!=Set.end();itr++){
			int p=*itr;
			set<int>::iterator itr2=itr;itr2++;
			bool last=itr2==Set.end();
			for(int &t=pos;t<V.size()&&V[t].first==p;t++){
				if(!first)g[pre].push_back(V[t].second);
				if(Set.size()!=1&&!last)g[V[t].second].push_back(pre+1);
			}
			if(Set.size()!=1)pre++;
			first=false;
		}
	}
	memset(used,0,sizeof(used));
	for(int i=0;i<pre;i++)if(used[i]==0)dfs(i);
	reverse(ans.begin(),ans.end());
	vector<int>ans2;
	ans2.clear();
	for(int i=0;i<ans.size();i++)if(ans[i]<m)putint(ans[i]+1),put(' ');
	return clear();
}