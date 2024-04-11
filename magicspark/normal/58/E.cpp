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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct state{
	int a,b,c,nxta,nxtb,nxtc,nxtadd,za,zb,zc;
	state(int x=-1,int y=0,int z=0,int xx=0,int yy=0,int zz=0,int aaaddd=0,int zza=0,int zzb=0,int zzc=0){a=x;b=y;c=z;nxta=xx;nxtb=yy;nxtc=zz,nxtadd=aaaddd;za=zza;zb=zzb;zc=zzc;}
}pre[12][12][12][2][2][2][2];
int dp[12][12][12][2][2][2][2];
string _a,_b,_c;
int aa,bb,cc;
int la,lb,lc,a[12],b[12],c[12];
bool read(){
	scanf("%d+%d=%d",&aa,&bb,&cc);
	_a=to_string(aa);_b=to_string(bb);_c=to_string(cc);
	la=_a.size();lb=_b.size();lc=_c.size();
	for(int i=0;i<la;i++)a[i]=_a[i]-'0';
	for(int i=0;i<lb;i++)b[i]=_b[i]-'0';
	for(int i=0;i<lc;i++)c[i]=_c[i]-'0';
	return la?true:false;
}
bool valid(int x){
	return x<=9&&x>=0;
}
int dfs(int sa,int sb,int sc,int add,int za,int zb,int zc){
	if(sa==la&&sb==lb&&sc==lc){
		if(add)return inf;
		else return 0;
	}
	if(dp[sa][sb][sc][add][za][zb][zc]<=2000)return dp[sa][sb][sc][add][za][zb][zc];
	int ret=inf;
	for(int new_a=0;new_a<10;new_a++){
		for(int new_b=0;new_b<10;new_b++){
			int new_c=new_a+new_b-add*10;
			if(valid(new_c)){
				bool A=(sa!=la&&new_a==a[sa]);
				bool B=(sb!=lb&&new_b==b[sb]);
				bool C=(sc!=lc&&new_c==c[sc]);
				int Add=(new_a!=0||za)+(new_b!=0||zb)+(new_c!=0||zc);
				if(A||B||C)if(ret>dfs(sa+A,sb+B,sc+C,0,za||new_a!=0,zb||new_b!=0,zc||new_c!=0)+Add){
					ret=dfs(sa+A,sb+B,sc+C,0,za||new_a!=0,zb||new_b!=0,zc||new_c!=0)+Add;
					pre[sa][sb][sc][add][za][zb][zc]=state(new_a,new_b,new_c,sa+A,sb+B,sc+C,0,za||new_a!=0,zb||new_b!=0,zc||new_c!=0);
				}
			}
			new_c++;
			if(valid(new_c)){
				bool A=(sa!=la&&new_a==a[sa]);
				bool B=(sb!=lb&&new_b==b[sb]);
				bool C=(sc!=lc&&new_c==c[sc]);
				int Add=(new_a!=0||za)+(new_b!=0||zb)+(new_c!=0||zc);
				if(A||B||C)if(ret>dfs(sa+A,sb+B,sc+C,1,za||new_a!=0,zb||new_b!=0,zc||new_c!=0)+Add){
					ret=dfs(sa+A,sb+B,sc+C,1,za||new_a!=0,zb||new_b!=0,zc||new_c!=0)+Add;
					pre[sa][sb][sc][add][za][zb][zc]=state(new_a,new_b,new_c,sa+A,sb+B,sc+C,1,za||new_a!=0,zb||new_b!=0,zc||new_c!=0);
				}
			}
		}
	}
	return dp[sa][sb][sc][add][za][zb][zc]=ret;
}
int main(){
	read();
	memset(dp,inf,sizeof dp);
	cerr<<dfs(0,0,0,0,0,0,0)<<endl;
	string ansa="",ansb="",ansc="";
	int now_a=0,now_b=0,now_c=0,now_add=0,za=0,zb=0,zc=0;
	while(now_a!=la||now_b!=lb||now_c!=lc){
//		cerr<<now_a<<" "<<now_b<<" "<<now_c<<" "<<now_add<<" "<<za<<" "<<zb<<" "<<zc<<endl;
		ansa.push_back('0'+pre[now_a][now_b][now_c][now_add][za][zb][zc].a);
		ansb.push_back('0'+pre[now_a][now_b][now_c][now_add][za][zb][zc].b);
		ansc.push_back('0'+pre[now_a][now_b][now_c][now_add][za][zb][zc].c);
		int nxta=pre[now_a][now_b][now_c][now_add][za][zb][zc].nxta;
		int nxtb=pre[now_a][now_b][now_c][now_add][za][zb][zc].nxtb;
		int nxtc=pre[now_a][now_b][now_c][now_add][za][zb][zc].nxtc;
		int nxtadd=pre[now_a][now_b][now_c][now_add][za][zb][zc].nxtadd;
		int nza=pre[now_a][now_b][now_c][now_add][za][zb][zc].za;
		int nzb=pre[now_a][now_b][now_c][now_add][za][zb][zc].zb;
		int nzc=pre[now_a][now_b][now_c][now_add][za][zb][zc].zc;
		now_a=nxta;now_b=nxtb;now_c=nxtc;now_add=nxtadd;za=nza;zb=nzb;zc=nzc;
	}
	while(ansa[0]=='0')ansa.erase(ansa.begin());
	while(ansb[0]=='0')ansb.erase(ansb.begin());
	while(ansc[0]=='0')ansc.erase(ansc.begin());
	cout<<ansa<<"+"<<ansb<<"="<<ansc<<endl;
	return 0;
}