//By MagicSpark
/*
Problem:1101C
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
struct P{
	int l,r,num;
};
bool operator<(P a,P b){
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
int n;
P a[111111];
int ans[111111];
int t;
void solve(){
	n=getint();
	for(int i=0;i<n;i++)a[i].l=getint(),a[i].r=getint(),a[i].num=i+1;
	sort(a,a+n);
	set<int>F;
	F.clear();
	int mx=-1;
	for(int i=0;i<n-1;i++){
		F.insert(a[i].num);
		mx=max(mx,a[i].r);
		if(mx<a[i+1].l){
			for(int j=0;j<n;j++){
				if(F.count(a[j].num)){
					ans[a[j].num]=1;
				}else{
					ans[a[j].num]=2;
				}
			}
			for(int j=1;j<=n;j++){
				putint(ans[j]);put(' ');
			}
			put('\n');return;
		}
	}
	put('-');put('1');
	put('\n');
}
int main(){
	t=getint();
	while(t--)solve();
	#ifdef fastio
		clear();
	#endif
	return 0;
}