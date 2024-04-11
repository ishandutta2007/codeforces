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
const int mod=998244353;
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
int n,m;
int l[300005],r[300005];
int x[22],y[22],ans[1<<20],cnt[300005];
vector<int>add[300005],del[300005];
vector<vector<int> >v;
vector<int>stk;
bool vis[300005];
vector<int>g[300005];
vector<int>sum[22][22];
int dp[44],tdp[44],fact[300005],inv[300005];
void dfs(int x){
	vis[x]=1;stk.push_back(x);
	for(auto to:g[x])if(!vis[to]){
		dfs(to);
	}
}
int C(int nn,int mm){
	return (ll)fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
signed main(){
	fact[0]=1;for(int i=1;i<=3e5;i++)fact[i]=(ll)fact[i-1]*i%mod;
	for(int i=0;i<=3e5;i++)inv[i]=modpow(fact[i],mod-2);
	n=getint();m=getint();
	for(int i=1;i<=n;i++){
		l[i]=getint();r[i]=getint();
		add[l[i]].push_back(i);
		del[r[i]+1].push_back(i);
	}
	set<pair<int,int> >E;
	for(int i=0;i<m;i++){
		x[i]=getint();y[i]=getint();
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]); 
		E.insert(make_pair(x[i],y[i]));
		E.insert(make_pair(y[i],x[i]));
	}
	for(int i=0;i<m;i++){
		if(!vis[x[i]]){
			dfs(x[i]);
			v.push_back(stk);
			stk.clear();
		}
		if(!vis[y[i]]){
			dfs(y[i]);
			v.push_back(stk);
			stk.clear();
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<=v[i].size();j++)sum[i][j].resize(1<<(v[i].size())),sum[i][j].shrink_to_fit();
		vector<int>valid(1<<(v[i].size()),1);
		for(int j=0;j<(1<<v[i].size());j++){
			for(int a=0;a<v[i].size();a++)if(j&(1<<a)){
				for(int b=a+1;b<v[i].size();b++)if(j&(1<<b)){
					if(E.count(make_pair(v[i][a],v[i][b])))valid[j]=0;
				}
			}
		}
		for(int j=0;j<(1<<v[i].size());j++){
			for(int sub=j;sub;sub=(sub-1)&j)if(valid[sub]){
				sum[i][__builtin_popcount(sub)][j]++;
			}
			sum[i][0][j]++;
		}
	}
//	cerr<<"ok init"<<" "<<v.size()<<endl;
	int ans=0;
	set<int>s;
	for(int i=1;i<=n;i++){
		for(auto v:add[i])s.insert(v);
		for(auto v:del[i])s.erase(v);
		memset(dp,0,sizeof dp);
		dp[0]=1;
		int tot=s.size(),high=0;
		for(int j=0;j<v.size();j++){
			int mask=0;
			for(int k=0;k<v[j].size();k++){
				if(s.count(v[j][k]))mask|=1<<k,tot--;
			}
			memset(tdp,0,sizeof tdp);
			for(int cur=0;cur<=high;cur++)for(int cnt=0;cnt<=v[j].size();cnt++)if(cur+cnt<=40){
				tdp[cur+cnt]+=(ll)dp[cur]*sum[j][cnt][mask]%mod;
				tdp[cur+cnt]%=mod;
			}
			high+=v[j].size(); 
			memcpy(dp,tdp,sizeof dp);
		}
		for(int j=0;j<=min(40,i);j++)if(i-j<=tot){
//			if(dp[j])cerr<<i<<" "<<tot<<" "<<j<<" "<<dp[j]<<" "<<C(tot,i-j)<<endl;
			ans+=(ll)dp[j]*C(tot,i-j)%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}