//By MagicSpark
/*
Problem:
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
int par[200002];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
bool unite(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return false;
	par[fx]=fy;
	return true;
}
struct edges{
	int x,y,cost;
};
bool operator<(edges a,edges b){
	if(a.cost!=b.cost)return a.cost<b.cost;
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
vector<edges>edge;
pair<int,int> res[200002];
int n,m;
int main(){
	for(int i=0;i<200002;i++)par[i]=i;
	n=getint();m=getint();
	for(int i=0;i<m;i++)edge.push_back((edges){getint(),getint(),getint()});
	sort(edge.begin(),edge.end());
	int l=0,r=0,ans=0;
	while(l<edge.size()){
		int cnt=0;
		while(r<edge.size()&&edge[l].cost==edge[r].cost){
			if(find(edge[r].x)!=find(edge[r].y))res[cnt++]=make_pair(edge[r].x,edge[r].y);
			r++;
		}
		l=r;
		for(int i=0;i<cnt;i++){
			if(!unite(res[i].first,res[i].second))ans++;
		}
	}
	cout<<ans<<endl;
	clear();
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
       	printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
	#endif
	return 0;
}