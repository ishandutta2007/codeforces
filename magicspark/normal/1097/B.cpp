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
using namespace fastio;
#define fastio
#define MP(...) make_pair(__VA_ARGS__)
#define pb push_back
#define rep(i,n) for (int i=0;i<(n);++i)
#define rep1(i,n) for (int i=1;i<=(n);++i)
#define Rep(i,a,b) for (int i=(a);i<=(b);++i)
#define repit(it,a) for (__typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define All(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define reunique(a) sort(All(a)),a.erase(unique(All(a)),a.end())
const int Maxn=20;
int n,a[Maxn],rt[Maxn];
signed main()
{
	n=getint();
	for(int i=0;i<n;i++)a[i]=getint();
	rep(mask,1<<n){
		rep(i,15)
			if (mask&(1<<i)) rt[i]=1;
			else rt[i]=-1;
		int res=0;
		rep(i,n) res+=(rt[i]*a[i]);
		if (res%360==0) return puts("YES")*0;
	}
	puts("NO");
	return 0;
}