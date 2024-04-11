//By MagicSpark
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
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
    	return ng?-r:r;
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
		if(x<0){
			put('-');
			x=-x;
		}
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
int n;
int graph[42][42];
ll mask[42];
map<string,int>disc;
set<int>tmp;
int cnt=0;
map<ll,int>memory;
inline ll lowbit(ll x){return x&(-x);}
inline int log(ll x){for(int i=0;i<64;i++)if((1ll<<i)==x)return i;}
int dfs(ll bitmask){
	if(memory.find(bitmask)!=memory.end())return memory[bitmask];
	return memory[bitmask]=max(dfs(bitmask-lowbit(bitmask)),1+dfs(bitmask&mask[log(lowbit(bitmask))]));
}
int main(){
	memory[0]=0;
	n=getint();getint();
	for(int i=0;i<42;i++)
		for(int j=0;j<42;j++)
			graph[i][j]=1;
	for(int i=0;i<n;i++){
		int type=getint();
		if(type==1){
			for(auto p:tmp)
				for(auto q:tmp)
					graph[p][q]=0;
			tmp.clear();
		}else{
			string s=getstr();
			if(disc.count(s)==0){
				disc[s]=cnt++;
			}
			int id=disc[s];
			tmp.insert(id);
		}
	}
	for(auto p:tmp)
		for(auto q:tmp)
			graph[p][q]=0;
	for(int i=0;i<disc.size();i++){
		ll T=0;
		for(int j=0;j<disc.size();j++)T+=((ll)graph[i][j]<<j);
		mask[i]=T;
	}
	cout<<dfs((1ll<<disc.size())-1)<<endl;
	return 0;
}
/*
5 3
1
2 motarack
2 mike
1
2 light
*/