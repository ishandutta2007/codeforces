#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
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
		if(x==0){
			put('0');
			return;
		}
		char c[40];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
}
using namespace fastio;
#define fastio
int n,m;
vector<pair<int,int> >g[1000005];
int dfn[1000005],lowlink[1000005],cnt=1;
vector<pair<int,int> >ng[1000005];
int sccval[1000005],mem[1000005],vis[1000005];
vector<int>all;
void dfs(int x){
	lowlink[x]=dfn[x]=cnt++;vis[x]=1;all.push_back(x);
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i].first;
		if(!dfn[to])dfs(to),lowlink[x]=min(lowlink[x],lowlink[to]);
		else if(vis[to])lowlink[x]=min(lowlink[x],lowlink[to]);
	}
	if(dfn[x]==lowlink[x]){
		while(1){
			int T=all.back();all.pop_back();
			lowlink[T]=dfn[x];vis[T]=0;if(T==x)break;
		}
	}
}
int dfs2(int x){
	if(mem[x]!=-1)return mem[x];
	int ret=sccval[x];
	for(int i=0;i<ng[x].size();i++){
		//cout<<x<<" "<<ng[x][i].first<<endl;
		ret=max(ret,ng[x][i].second+dfs2(ng[x][i].first)+sccval[x]);
	}
	return mem[x]=ret;
}
int memory[1000005],ini1[1000005],ini[1000005];
int Get(int x){
	//calc 1*2+2*3+....+t*(t+1)
	if(memory[x]!=0||x==0)memory[x];
	int ret=0;
	for(int i=1;i<=x;i++){
		ret+=i*(i+1);
		memory[i]=ret;
	}
	return ret;
}
int calc(int w){
	int l=0,r=20000,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(ini1[mid]>w) r=mid-1;
		else l=mid+1;
	}
//	cout<<r<<" "<<1ll*w*(r+1)-ini[r]<<endl;
	return 1ll*w*(r+1)-ini[r];
}
signed main(){
	for(int i=1;i<=1000005;i++){
		ini1[i]=ini1[i-1]+i;
	}
	for(int i=1;i<=1000005;i++){
		ini[i]=ini[i-1]+ini1[i];
	}
	n=getint();m=getint();
	for(int i=0;i<m;i++){
		int x=getint(),y=getint(),z=getint();
		g[x].push_back(make_pair(y,z));
	}
	int s=getint();
	dfs(s);
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	//debug();
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			int to=g[i][j].first,val=g[i][j].second;
			if(lowlink[to]==lowlink[i]){
				sccval[lowlink[to]]+=calc(val);
			}else{
				ng[lowlink[i]].push_back(make_pair(lowlink[to],val));
			}
		}
	}
	//set<int>P;
	//for(int i=1;i<=n;i++)P.insert(lowlink[i]);
	memset(mem,-1,sizeof(mem));
	int ans=dfs2(1);
	cout<<ans<<endl;
	return 0;
}