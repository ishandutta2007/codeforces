//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
#include<bits/stdc++.h>
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
	int itr=0,len=0;
	char get(){
		if(itr==len)len=fread(in,1,100000,stdin),itr=0;
		if(len==0)return EOF;
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
	int getnum(){
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
	int putint(int x){
		char c[40];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
}
using namespace fastio;
int t,n,lens,used[200];
string s,a,b;
char mp[200];
bool ok=false;
void dfs(int cur,bool aa,bool bb){
	if(cur==lens||(aa&&bb)){
		ok=true;
		return;
	}
	if(mp[s[cur]]){
		if((aa || mp[s[cur]]>=a[cur])&&(bb || mp[s[cur]]<=b[cur]))dfs(cur+1,(aa || mp[s[cur]]>a[cur]),(bb || mp[s[cur]]<b[cur]));
		return;
	}
	for(int i='a';i<'a'+n;i++)if(!used[i]){
		if((!aa && i<a[cur])||(!bb&&i>b[cur]))continue;
		used[i]=1;
		mp[s[cur]]=i;
		dfs(cur+1,aa||i>a[cur],bb||i<b[cur]);
		if(ok)return;
		used[i]=mp[s[cur]]=0;
	}
}
int main(){
	t=getnum();
	while(t--){
		n=getnum();s=getstr();a=getstr();b=getstr();
		lens=s.size();
		memset(used,0,sizeof(used));
		memset(mp,0,sizeof(mp));
		ok=false;
		dfs(0,false,false);
		if(!ok){
			putstr("NO\n");
			continue;
		}
		for(int i='a',now='a';i<'a'+n;i++)if(!mp[i]) {
			while(used[now])now++;
			mp[i]=now;
			used[now]=true;
		}
		putstr("YES\n");
		for(int i='a';i<'a'+n;i++)put(mp[i]);
		put('\n');
	}
	return clear();
}