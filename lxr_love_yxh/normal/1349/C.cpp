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
#define int long long
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
int n,m,t;
string s[1005];
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int dist[1005][1005];
signed main(){
	n=getint();m=getint();t=getint();
	for(int i=1;i<=n;i++)s[i]=" "+getstr();
	memset(dist,inf,sizeof dist);
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bool can=0;
			for(int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx>0&&ny>0&&nx<=n&&ny<=m){
					if(s[i][j]==s[nx][ny]){
						dist[i][j]=dist[nx][ny]=0;
						can=1;
					}
				}
			}
			if(can)q.push(make_pair(i,j));
		}
	}
	while(!q.empty()){
		auto got=q.front();q.pop();
		int i=got.first,j=got.second;
		for(int k=0;k<4;k++){
			int nx=i+dx[k],ny=j+dy[k];
			if(nx>0&&ny>0&&nx<=n&&ny<=m){
				if(dist[nx][ny]>dist[i][j]+1){
					dist[nx][ny]=dist[i][j]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	while(t--){
		int x=getint(),y=getint(),z=getint();
		if(z<dist[x][y]){
			put(s[x][y]);put('\n');
		}else{
			put((z-dist[x][y])%2?'1'+'0'-s[x][y]:s[x][y]);put('\n');
		}
	}
	clear();
	return 0;
}