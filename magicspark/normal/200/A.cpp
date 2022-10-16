/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,m,k,xx,yy,dd;
int p11[2005][2005],p12[2005][2005],p21[2005][2005],p22[2005][2005];
int find11(int x,int y){
	return p11[x][y]==x?x:p11[x][y]=find11(p11[x][y],y);
}
int find12(int x,int y){
	return p12[x][y]==x?x:p12[x][y]=find12(p12[x][y],y);
}
int find21(int x,int y){
	return p21[x][y]==y?y:p21[x][y]=find21(x,p21[x][y]);
}
int find22(int x,int y){
	return p22[x][y]==y?y:p22[x][y]=find22(x,p22[x][y]);
}
void del(int x,int y){
	p11[x][y]=find11(x+1,y);
	p12[x][y]=find12(x-1,y);
	p21[x][y]=find21(x,y+1);
	p22[x][y]=find22(x,y-1);
}
int main(){
	n=getint();m=getint();k=getint();
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			p11[i][j]=i;p12[i][j]=i;
			p21[i][j]=j;p22[i][j]=j;
		}
	}
	while(k--){
		int x=getint(),y=getint();
		int ax=inf,ay=inf,ad=inf;
		if(n<m){
			int st=max(1,x-250),ed=min(n,st+500);
			st=max(1,ed-500);
			for(int i=st;i<=ed;i++){
				xx=i;yy=find21(i,y);
				if(yy<=m){
					dd=abs(x-xx)+abs(y-yy);
					if(dd<ad||(dd==ad&&xx<ax)||(dd==ad&&xx==ax&&yy<ay)){
						ad=dd;ax=xx;ay=yy;
					}
				}
				xx=i;yy=find22(i,y);
				if(yy>=1){
					dd=abs(x-xx)+abs(y-yy);
					if(dd<ad||(dd==ad&&xx<ax)||(dd==ad&&xx==ax&&yy<ay)){
						ad=dd;ax=xx;ay=yy;
					}
				}
			}
		}else{
			int st=max(1,y-250),ed=min(m,st+500);
			st=max(1,ed-500);
			for(int i=st;i<=ed;i++){
				yy=i;xx=find11(x,i);
				if(xx<=n){
					dd=abs(x-xx)+abs(y-yy);
					if(dd<ad||(dd==ad&&xx<ax)||(dd==ad&&xx==ax&&yy<ay)){
						ad=dd;ax=xx;ay=yy;
					}
				}
				yy=i;xx=find12(x,i);
				if(xx>=1){
					dd=abs(x-xx)+abs(y-yy);
					if(dd<ad||(dd==ad&&xx<ax)||(dd==ad&&xx==ax&&yy<ay)){
						ad=dd;ax=xx;ay=yy;
					}
				}
			}
		}
		putint(ax);putln(ay);
		del(ax,ay);
	}
	clear();
	return 0;
}