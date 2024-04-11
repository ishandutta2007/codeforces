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
	pair<int,int>getpair(){
		pair<int,int>ret;
		ret.first=getint();
		ret.second=getint();
		return ret;
	}
}
using namespace fastio;
#define fastio
int n,m;
int a[111111];
int b[111111];
struct Tp{
	int first,second,third;
};
bool operator<(Tp a,Tp b){
	if(a.first!=b.first)return a.first<b.first;
	if(a.second!=b.second)return a.second<b.second;
	return a.third<b.third;
}
Tp p[111111];
int ans=0;
vector<int>res,T;
void tag(int l,int r){
	for(int i=l;i<=r;i++)b[i]--;
}
void calc(){
	int tmp=*max_element(b+1,b+n+1)-*min_element(b+1,b+n+1);
	if(tmp>ans){
		ans=tmp;
		res=T;
	}
}
int main(){
	n=getint();m=getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	for(int i=0;i<m;i++)p[i].first=getint(),p[i].second=getint(),p[i].third=i;
	sort(p,p+m);
	memcpy(b,a,sizeof(b));
	for(int i=0;i<m;i++){
		T.push_back(p[i].third);
		tag(p[i].first,p[i].second);
		calc();
	}
	for(int i=0;i<m;i++)swap(p[i].first,p[i].second);
	sort(p,p+m);
	reverse(p,p+m);
	T.clear();
	memcpy(b,a,sizeof(b));
	calc();
	for(int i=0;i<m;i++){
		T.push_back(p[i].third);
		tag(p[i].second,p[i].first);
		calc();
	}
	cout<<ans<<endl;
	cout<<res.size()<<endl;
	for(int x:res)cout<<x+1<<" ";cout<<endl;
	return 0;
}