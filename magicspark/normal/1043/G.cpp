/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
const double eps=1e-9;
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
int n,q;
string s;
struct SA{
	int sa[200005],rk[200005],cnt[200005],tp[200005],h[200005],st[18][200005],lg[200005];
	void qsort(){
		memset(cnt,0,sizeof cnt);
		const int lmt=*max_element(rk+1,rk+n+1);
		for(int i=1;i<=n;i++)cnt[rk[i]]++;
		for(int i=1;i<=lmt;i++)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--)sa[cnt[rk[tp[i]]]--]=tp[i];
	}
	void build(){
		memset(sa,0,sizeof sa);
		memset(rk,0,sizeof rk);
		for(int i=1;i<=n;i++)rk[i]=s[i]-'a'+1,tp[i]=i;
		qsort();
		for(int w=1;w<=n;w<<=1){
			memcpy(tp,sa,sizeof tp);
			int pos=0;
			for(int i=n-w+1;i<=n;i++)tp[++pos]=i;
			for(int i=1;i<=n;i++)if(sa[i]>w)tp[++pos]=sa[i]-w;
			qsort();pos=0;
			memcpy(tp,rk,sizeof tp);
			rk[sa[1]]=++pos;
			for(int i=2;i<=n;i++)rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]?pos:++pos);
		}
		for(int i=1;i<=n;i++){
			if(rk[i]==1)continue;
				int tmp=h[rk[i-1]];if(tmp)tmp--;
			while(s[i+tmp]==s[sa[rk[i]-1]+tmp])tmp++;
			h[rk[i]]=tmp;
		}
		for(int i=2;i<=n;i++)st[0][i]=h[i];
		for(int i=1;i<18;i++)for(int j=1;j+(1<<i-1)<=n;j++)st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
		lg[1]=0;for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
	}
	int get_lcp(int x,int y){
		int l=rk[x],r=rk[y];if(l>r)swap(l,r);l++;
		const int lvl=lg[r-l+1];
		return min(st[lvl][l],st[lvl][r-(1<<lvl)+1]);
	}
}S1,S2;
vector<int>add[200005],del[200005];
vector<int>radd[200005],rdel[200005];
int fl[200005],fr[200005];
int nxt[200005][26];
struct SGT{
	#define SIZE 262144
	int f[SIZE<<1];
	SGT(){memset(f,inf,sizeof f);}
	void update(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=min(f[x<<1],f[x<<1|1]);
		}
	}
	int query(int l,int r,int k,int ql,int qr){
		if(qr<l||r<ql)return inf;
		if(ql<=l&&r<=qr)return f[k];
		return min(query(l,(l+r)/2,k<<1,ql,qr),query((l+r)/2+1,r,k<<1|1,ql,qr));
	}
}T;
int main(){
	n=getint();s=" "+getstr()+"%";S1.build();
	reverse(s.begin()+1,s.begin()+n+1);S2.build();
	reverse(s.begin()+1,s.begin()+n+1);
	q=getint();
	for(int i=1;i<=n;i++){
		for(int j=i+i;j<=n;j+=i){
			int k=j-i;
			if(S1.get_lcp(k,j)+S2.get_lcp(n-k+1,n-j+1)>=i+1){
				int st=k-min(i-1,S2.get_lcp(n-k+1,n-j+1)-1);
				int ed=k-max(0,i-S1.get_lcp(k,j));
				int delta=max(ed+i+i-1-n,0);ed-=delta;
				add[st].push_back(i);
				del[ed+1].push_back(i);
				radd[min(n,ed+i+i-1)].push_back(i);
                rdel[min(n,st+i+i-2)].push_back(i);
			}
		}
	}
	multiset<int>s;
	for(int i=1;i<=n;i++){
		for(auto u:add[i])s.insert(u);
		for(auto u:del[i])s.erase(s.find(u));
		if(s.empty())fl[i]=inf;
		else fl[i]=i+*s.begin()*2-1;
	}
	s.clear();
	for(int i=n;i>=1;i--){
		for(auto u:radd[i])s.insert(u);
		for(auto u:rdel[i])s.erase(s.find(u));
		if(s.empty())fr[i]=-inf;
		else fr[i]=i-*s.begin()*2+1;
	}
//	for(int i=1;i<=n;i++)cerr<<i<<" "<<fl[i]<<" "<<fr[i]<<endl; 
	memset(nxt,inf,sizeof nxt);
	for(int i=n;i>=0;i--){
		memcpy(nxt[i],nxt[i+1],sizeof nxt[i]);
		if(i<n)nxt[i][::s[i+1]-'a']=i+1;
	}
	for(int i=1;i<=n;i++)T.update(i,fl[i]);
	while(q--){
		int l=getint(),r=getint();
		char c1=::s[l];
		//check -1
		int got=0;
		for(int i=0;i<26;i++){
			if(nxt[l-1][i]<=r&&nxt[nxt[l-1][i]][i]<=r)got=i+1;
		}
//		cerr<<l<<" "<<r<<" "<<got<<endl;
		if(!got){
			puts("-1");
			continue;
		}
		//check 1
		bool can=0;
		for(int i=1;i*i<=n;i++)if((r-l+1)%i==0){
			int x=i;
			if(l+x<=r&&S1.get_lcp(l,l+x)>=r-l+1-x)can=1;
			x=(r-l+1)/i;
			if(l+x<=r&&S1.get_lcp(l,l+x)>=r-l+1-x)can=1;
		}
		if(can){
			puts("1");
			continue;
		}
		//check BAA&AAB
		bool gg=0;
		if(fl[l]<=r||fr[r]>=l){
			puts("2");
			continue;
		}
		//check ABA(range border)
		/*
		bool hv=0;
		for(int i=1;i*2<=(r-l+1);i++){
			if(getstr(::s,l,l+i-1)==getstr(::s,r-i+1,r)&&l+i-1<r-i+1){
				hv=1;break;
			}
		}
		if(hv){
			puts("2");
			continue;
		}
		*/
		bool hv=0;
		for(int i=r;i>=r-500&&i>l;i--)if(i+S1.get_lcp(l,i)>r)hv=1;
		for(int i=max(1,S1.rk[l]-500);i<=min(n,S1.rk[l]+500);i++){
			int x=S1.sa[i];
			if(l<x&&x<=r)if(x+S1.get_lcp(x,l)>r)hv=1;
		}
		if(hv){
			puts("2");
			continue;
		}
		//aBaC||BaCa
		if(nxt[l][::s[l]-'a']<=r||nxt[l-1][::s[r]-'a']!=r){
			puts("3");
			continue;
		}
		//BAAC
		bool vis=0;
		if(T.query(0,SIZE-1,1,l,r)<=r){
			puts("3");
			continue;
		}
		puts("4");
	}
	return 0;
}