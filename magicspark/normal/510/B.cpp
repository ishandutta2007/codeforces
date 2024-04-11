//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
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
/*using namespace fastio;
#define fastio
*/
int n,m;
string s[55];
const int MX=1e6;
struct UFS{
	int par[MX],rank[MX];
	void init(int n){
		for(int i=0;i<n;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	void remove(int i){
		par[i]=i;
		rank[i]=0;
	}
	int find(int x){
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		cerr<<x<<" "<<y<<endl;
		x=find(x);
		y=find(y);
		if(x==y){
			puts("Yes");
			exit(0);
		}
		if(rank[x]<rank[y]){
			par[x]=y;
		}
		else{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
}uf;
int dx[]={1,0},dy[]={0,1};
int main(){
	uf.init(MX-1);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<2;k++)if(i+dx[k]<n&&j+dy[k]<m&&s[i][j]==s[i+dx[k]][j+dy[k]])uf.unite(i*100+j,(i+dx[k])*100+(j+dy[k]));
	puts("No");
	#ifndef ONLINE_JUDGE
		#ifndef fastio
			printf("\n-----\n");
        	printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
		#endif
	#endif
	#ifdef fastio
		clear();
	#endif
	return 0;
}