#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
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
			put('0');
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
using fastio::getint;
using fastio::getstr;
using fastio::putint;
using fastio::putstr;
using fastio::clear;
using fastio::putln;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
pair<int,int>s[333333];
signed main(){
	n=getint();k=getint();
	for(int i=0;i<n;i++)s[i].second=getint(),s[i].first=getint();
	sort(s,s+n);reverse(s,s+n);
	int ans=0,sum=0;multiset<int>nums;
	for(int i=0;i<n;i++){
		sum+=s[i].second;nums.insert(s[i].second);
		if(nums.size()>k){
			sum-=*nums.begin();
			nums.erase(nums.begin());
		}
		ans=max(ans,s[i].first*sum);
	}
	cout<<ans<<endl;
	return 0;
}