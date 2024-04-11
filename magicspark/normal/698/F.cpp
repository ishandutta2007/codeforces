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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
int n,p[1000005],cnt_pos[1000005],cnt_val[1000005],occ[1000005],fc[1000005];
vector<int>buc[1000005];
int pos_to_val[1000005],val_to_pos[1000005];
int get(int x){
	return n/x;
}
bool match(int pos,int val){
//	assert(pos==val);
	if(pos_to_val[pos]!=-1&&pos_to_val[pos]!=val)return false;
	if(val_to_pos[val]!=-1&&val_to_pos[val]!=pos)return false;
	pos_to_val[pos]=val;val_to_pos[val]=pos;
	return true;
}
bool solve(int x,int y){
	if(fc[x]==x&&get(x)==1)x=1;
	if(fc[y]==y&&get(y)==1)y=1;
	vector<int>vx,vy;
	while(x!=1){
		if(vx.empty()||fc[x]!=vx.back())vx.push_back(fc[x]);
		x/=fc[x];
	}
	while(y!=1){
		if(vy.empty()||fc[y]!=vy.back())vy.push_back(fc[y]);
		y/=fc[y];
	}
	if(vx.size()!=vy.size())return false;
	for(int i=0;i<vx.size();i++){
		if(get(vx[i])!=get(vy[i]))return false;
		if(!match(vx[i],vy[i]))return false;
	}
	return true;
}
int calc(int x){
	if(fc[x]==x&&x*2>n)return 1;
	int lst=-1,cur=1;
	while(x!=1){
		if(fc[x]!=lst)cur*=fc[x];
		lst=fc[x];x/=fc[x];
	}
	return cur;
}
int main(){
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	n=getint();
	memset(pos_to_val,-1,sizeof pos_to_val);
	memset(val_to_pos,-1,sizeof val_to_pos);
	for(int i=1;i<=n;i++)p[i]=getint();
	memset(fc,inf,sizeof fc);
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j+=i)fc[j]=min(fc[j],i);
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0)cnt_pos[calc(i)]++;
		else{
			if(!solve(i,p[i])){
				puts("0");
				return 0;
			}
			occ[p[i]]=1;
		}
	}
	int ans=1;
	for(int i=2;i<=n;i++)if(get(i)!=get(i-1)){
		if(get(i)==1)break;
		int j=i;while(get(j)==get(i))j++;j--;
		int tot=0;
		for(int t=i;t<=j;t++){
			if(fc[t]==t&&pos_to_val[t]==-1)tot++;
		}
		for(int t=1;t<=tot;t++)ans=1ll*ans*t%mod;
	}
	for(int i=1;i<=n;i++)if(!occ[i])cnt_val[calc(i)]++;
	for(int i=1;i<=n;i++)if(cnt_val[i]){
		for(int j=1;j<=cnt_val[i];j++)ans=1ll*ans*j%mod;
	}
	cout<<ans<<endl;
	return 0;
}