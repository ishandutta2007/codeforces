#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
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
    	int ret=0;char ch=get();
		while (ch<'0'||ch>'9'){
			ch=get();if(ch=='-')return -getint();
		}
		while ('0'<=ch&&ch<='9'){
			ret=ret*10-48+ch;
			ch=get();
		}
		return ret;
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
			putint(-x);
			return;
		}
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
		put(' ');
	}
	void putln(int x){
		if(x<0){
			put('-');
			putint(-x);
			return;
		}
		if(x==0){
			put('0');put('\n');
			return;
		}
		char c[40];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
		put('\n');
	}
}
using namespace fastio;
int n,m;
int main(){
	cin>>n>>m;
	for(int line=1;line<=n/2;line++){
		int oppo=n+1-line;
		for(int j=1;j<=m;j++){
			putint(line);putln(j);
			putint(oppo);putln(m+1-j);
		}
	}
	if(n&1){
		for(int i=1;i<=(m+1)/2;i++){
			putint((n+1)/2);putln(i);
			if(m-i+1!=i)putint((n+1)/2),putln(m-i+1);
		}
	}
	clear();
	return 0;
}