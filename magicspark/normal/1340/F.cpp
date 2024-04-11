/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
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
int n,k,q,a[100005];
const int maxn=1e5+333;
const int size=333;
const int cnt=maxn/size;
const unsigned mul=19260817;
unsigned pw[size+5];
struct hash_t{
	int arr[size],sz;
	unsigned hsh[size];
	void init(int *f,int siz){
		sz=siz;if(siz==0)return;
		for(int i=0;i<sz;i++)arr[i]=f[i];
		hsh[0]=arr[0]+1;
		for(int i=1;i<sz;i++){
			hsh[i]=hsh[i-1]*mul+(arr[i]+1);
		}
	}
	unsigned get_hash(int l,int r){
		if(r>=sz)assert(0);
		if(l==0)return hsh[r];
		return hsh[r]-hsh[l-1]*pw[r-l+1];
	}
};
int add[size],sza,sub[size],szb;
struct block{
	hash_t ins,del;
	bool can;
	void reset(int *f,int sz){
		sza=0;szb=0;can=1;
		for(int i=0;i<sz;i++){
			if(f[i]<0){
				if(sza){
					if(add[sza-1]!=-f[i]){
						can=0;break;
					}else sza--;
				}else sub[szb++]=-f[i];
			}else{
				add[sza++]=f[i];
			}
		}
		ins.init(add,sza);
		reverse(sub,sub+szb);
		del.init(sub,szb);
	}
}buc[cnt+5];
vector<pair<int,int> >cur;
//<ind,r>
bool erase(hash_t arr){
	if(!arr.sz)return true;
	if(!cur.size())return false;
	sza=arr.sz;
	while(sza&&cur.size()){
		if(cur.back().second>sza){
			//partically delete
			int ind=cur.back().first,sz=cur.back().second;
			if(buc[ind].ins.get_hash(sz-sza,sz-1)!=arr.get_hash(0,sza-1)){
				return false;
			}else{
				cur.back().second-=sza;return true;
			}
		}else{
			//totally delete
			int ind=cur.back().first,sz=cur.back().second;
			if(buc[ind].ins.get_hash(0,sz-1)!=arr.get_hash(sza-sz,sza-1)){
				return false;
			}else{
				sza-=sz;cur.pop_back();if(sza==0)return true;
			}
		}
	}
	return false;
}
bool query(int l,int r){
	cur.clear();
	buc[cnt+2].reset(a+l,l%size==0?0:min(r-l+1,size-l%size));
	if(l%size){
		if(!erase(buc[cnt+2].del))return false;
		if(!buc[cnt+2].can)return false;
		if(buc[cnt+2].ins.sz)cur.push_back(make_pair(cnt+2,buc[cnt+2].ins.sz));
	}
	while(l%size&&l<=r)l++;
	for(;l+size-1<=r;l+=size){
		if(!erase(buc[l/size].del))return false;
		if(!buc[l/size].can)return false;
		if(buc[l/size].ins.sz)cur.push_back(make_pair(l/size,buc[l/size].ins.sz));
	}
	if(l<=r){
		buc[cnt+3].reset(a+l,r-l+1);
		if(!erase(buc[cnt+3].del))return false;
		if(!buc[cnt+3].can)return false;
		if(buc[cnt+3].ins.sz)
		cur.push_back(make_pair(cnt+3,buc[cnt+3].ins.sz));
	}
	return !cur.size();
}
int main(){
	pw[0]=1;for(int i=1;i<size+5;i++)pw[i]=pw[i-1]*mul;
	n=getint();k=getint();
	for(int i=0;i<n;i++){
		a[i]=getint();
	}
	for(int i=0;i<n;i+=size){
		buc[i/size].reset(a+i,min(size,n-i));
	}
	q=getint();int tot=0;
	while(q--){
		int type=getint();
		if(type==1){
			int i=getint()-1,t=getint();
			a[i]=t;buc[i/size].reset(a+(i/size*size),min(size,n-i/size*size));
		}else{
			int l=getint()-1,r=getint()-1;
			putstr(query(l,r)?"Yes\n":"No\n");
		}
	}
	clear();
	return 0;
}