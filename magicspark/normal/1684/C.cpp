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
        while(isspace(ch))ch=get();
        while(!isspace(ch))ret.push_back(ch),ch=get();
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
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
int T,n,m,pos;
vector<vector<int> >a,id;
bool cmp(int x,int y){return make_pair(a[pos][x],x)<make_pair(a[pos][y],y);}
int main(){
	T=getint();
	while(T--){
		n=getint();m=getint();
		a.clear();a.resize(n);
		for(int i=0;i<n;i++)a[i].resize(m,0);
		id=a;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)a[i][j]=getint(),id[i][j]=j;
			pos=i;sort(id[i].begin(),id[i].end(),cmp);
		}
		vector<int>pos(n,0),used(m,0);
		vector<int>all;
		bool valid=1;
		for(int i=0;i<m;i++){
			int mx=0;
			for(int j=0;j<n;j++){
				while(used[id[j][pos[j]]])pos[j]++;
//				cerr<<j<<" "<<pos[j]<<" "<<id[j][pos[j]]<<endl;
				mx=max(mx,id[j][pos[j]]);
			}
			all.push_back(mx);
			for(int j=0;j<n;j++){
//				cerr<<id[j][pos[j]]<<" "<<mx<<endl;
				if(a[j][id[j][pos[j]]]!=a[j][mx])valid=0;
			}
			if(!valid)break;
			used[mx]=1;
		}
		if(!valid){
			cout<<-1<<endl;
			continue;
		}
		for(auto u:all)cerr<<u<<" ";cerr<<endl;
		vector<int>occ;
		for(int i=0;i<all.size();i++){
			if(all[i]!=i)occ.push_back(i);
		}
		while(occ.size()>2)occ.erase(occ.begin()+1);
		if(occ.size()==2){
				vector<int>ord(m,0);bool can=1;
		for(int i=0;i<m;i++)ord[i]=i;
		swap(ord[occ[0]],ord[occ[1]]);
		for(int i=0;i<n;i++){
			int prv=-1e9;
			for(int j=0;j<m;j++){
				if(a[i][ord[j]]<prv)can=0;
				prv=a[i][ord[j]];
			}
		}
		if(!can){
			cout<<-1<<endl;
			continue;
		}
			cout<<occ[0]+1<<" "<<occ[1]+1<<endl;
			continue;
		}
		cout<<1<<" "<<1<<endl;
	}
	return 0;
}