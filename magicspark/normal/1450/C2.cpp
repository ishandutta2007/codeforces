/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
    template<class T>void putint(T x){
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
    template<class T>void putln(T x){
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
int t,n,cx[5],co[5],tot;
string s[305],ss[305];
bool check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>=2&&s[i][j]=='X'&&s[i-1][j]=='X'&&s[i-2][j]=='X')return false;
			if(i>=2&&s[i][j]=='O'&&s[i-1][j]=='O'&&s[i-2][j]=='O')return false;
			if(j>=2&&s[i][j]=='O'&&s[i][j-1]=='O'&&s[i][j-2]=='O')return false;
			if(j>=2&&s[i][j]=='X'&&s[i][j-1]=='X'&&s[i][j-2]=='X')return false;
		}
	}
}
int main(){
	t=getint();
	while(t--){
		memset(cx,0,sizeof cx);
		memset(co,0,sizeof co);
		n=getint();tot=0;
		for(int i=0;i<n;i++){
			s[i]=getstr();
			for(int j=0;j<n;j++){
				if(s[i][j]=='X')cx[(i+j)%3]++,tot++;
				if(s[i][j]=='O')co[(i+j)%3]++,tot++;
			}
		}
		for(int ii=0;ii<9;ii++){
			int i=ii/3,j=ii%3; 
				if(cx[i]+co[j]<=tot/3){
					for(int a=0;a<n;a++)ss[i]=s[i];
					for(int a=0;a<n;a++){
						for(int b=0;b<n;b++){
							if(s[a][b]=='X'&&(a+b)%3==i)s[a][b]='O';
							else if(s[a][b]=='O'&&(a+b)%3==j)s[a][b]='X';
						}
					}
					if(check()){
						break;
					}
					for(int a=0;a<n;a++)s[i]=ss[i];
				}
		}
		for(int i=0;i<n;i++){
			putstr(s[i]);put('\n');
		}
	}
	clear();
	return 0;
}