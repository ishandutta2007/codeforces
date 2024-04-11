/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
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
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
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
            put('0');put(' ');
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
            putln(-x);
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
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n;
string s[300005];
int x[300005],y[300005];
pair<int,int>rx,ry,rdif;
bool check(int x,int y,pair<int,int>rx,pair<int,int>ry,pair<int,int>rdif){
	return rx.first<=x&&x<=rx.second&&ry.first<=y&&y<=ry.second&&rdif.first<=x-y&&x-y<=rdif.second;
}
bool check(int val){
	rx=make_pair(0,inf);
	ry=make_pair(0,inf);
	rdif=make_pair(-inf,inf);
	for(int i=1;i<=n;i++){
		rx.first=max(rx.first,x[i]-val);
		rx.second=min(rx.second,x[i]+val);
		ry.first=max(ry.first,y[i]-val);
		ry.second=min(ry.second,y[i]+val);
		rdif.first=max(rdif.first,x[i]-y[i]-val);
		rdif.second=min(rdif.second,x[i]-y[i]+val);
	}
	if(rx.first>rx.second)return 0;
	if(ry.first>ry.second)return 0;
	if(rdif.first>rdif.second)return 0;
	int mndif=rx.first-ry.second,mxdif=rx.second-ry.first;
	if(mxdif<rdif.first||rdif.second<mndif)return 0;
	/*
	bool z=0,f=0;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			if(check(i,j,rx,ry,rdif)){
				if(i==0&&j==0)z=1;
				else f=1;
			}
		}
	}
	if(z&&!f)return 0;
	*/
	return 1;
}
void construct(int val){
	rx=make_pair(0,inf);
	ry=make_pair(0,inf);
	rdif=make_pair(-inf,inf);
	for(int i=1;i<=n;i++){
		rx.first=max(rx.first,x[i]-val);
		rx.second=min(rx.second,x[i]+val);
		ry.first=max(ry.first,y[i]-val);
		ry.second=min(ry.second,y[i]+val);
		rdif.first=max(rdif.first,x[i]-y[i]-val);
		rdif.second=min(rdif.second,x[i]-y[i]+val);
	}
	assert(rx.first<=rx.second);
	assert(ry.first<=ry.second);
	assert(rdif.first<=rdif.second);
	int mndif=rx.first-ry.second,mxdif=rx.second-ry.first;
	mndif=max(mndif,rdif.first);
	mxdif=min(mxdif,rdif.second);
	int ansx=rx.first,ansy=ry.first;
//	cerr<<mndif<<" "<<mxdif<<endl;
	while(ansx-ansy<mndif)ansx++;
	while(ansx-ansy>mxdif)ansy++;
	if(ansx==0&&ansy==0){
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				if(check(i,j,rx,ry,rdif)){
					if(i==0&&j==0)continue;
					ansx=i;ansy=j;
				}
			}
		}
	}
	assert(ansx+ansy>0);
//	cout<<ansx+ansy<<endl;
	for(int i=1;i<=ansx;i++)putchar('N');
	for(int i=1;i<=ansy;i++)putchar('B');
}
int main(){
	n=getint();
	for(int i=1;i<=n;i++)s[i]=getstr();
	for(int i=1;i<=n;i++){
		for(char c:s[i])if(c=='N')x[i]++;else y[i]++;
	}
	int l=-1,r=3e5+5;
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	construct(r);
	return 0;
}