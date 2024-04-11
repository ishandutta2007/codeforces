//By MagicSpark
/*
Problem:1100E
Main Idea:
Status:
*/
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
int n,m;
vector<pair<int,int> >g[100005];
int used[100005];
bool is;
int cnt;
void dfs(int x,int par,int &cmp){
	//cerr<<x<<" "<<par<<" "<<cmp<<endl;
	used[x]=1;
	for(auto p:g[x]){
		if(p.second<=cmp)continue;
		if(used[p.first]==1)is=true;
		if(!used[p.first]){
			dfs(p.first,x,cmp);
		}
	}
	used[x]=2;
}
bool iscircle(int x){
	//value>=x -> valid
	memset(used,0,sizeof(used));
	is=false;
	for(int i=1;i<=n;i++)if(!used[i])dfs(i,-1,x);
	return is;
}
int val[100005];
vector<int>ans;
void dfs2(int x,int &cmp){
	used[x]=true;
	for(auto p:g[x]){
		if(p.second>cmp&&!used[p.first]){
			dfs2(p.first,cmp);
		}
	}
	ans.push_back(x);
}
void topsort(int x){
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[i])dfs2(i,x);
	}
	memset(val,-1,sizeof(val));
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		val[ans[i]]=i+1;
	}
}
struct edge{
	int from,to,tim,ord;
};
vector<edge>vec;
int main(){
	n=getint();m=getint();
	for(int i=0;i<m;i++){
		int x=getint(),y=getint(),c=getint();
		g[x].push_back(make_pair(y,c));
		vec.push_back((edge){x,y,c,i+1});
	}
	int l=-1,r=1e9+5;
	while(r-l>1){
		int mid=l+r>>1;
		if(iscircle(mid))l=mid;
		else r=mid;
	}
	cout<<r<<" ";
	topsort(r);
	//for(int i=1;i<=n;i++)cout<<val[i]<<" ";cout<<endl;
	vector<int>answer;
	answer.clear();
	for(int i=0;i<vec.size();i++){
		if(vec[i].tim<=r){
			if(val[vec[i].from]>val[vec[i].to])answer.push_back(vec[i].ord);
		}
	}
	cout<<answer.size()<<endl;
	for(auto p:answer)cout<<p<<" ";
	cout<<endl;
	return 0;
}