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
#define int long long
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
int n,m,ans;
struct SGT{
	#define SIZE 131072
	int f[SIZE<<1],lazy[SIZE<<1],l,r,v;
	SGT(){memset(f,0,sizeof f);memset(lazy,0,sizeof lazy);}
	void _add(int ll,int rr,int k){
		if(rr<l||r<ll)return;
		if(l<=ll&&rr<=r){
			lazy[k]+=v;return;
		}
		lazy[k<<1]+=lazy[k];lazy[k<<1|1]+=lazy[k];lazy[k]=0;
		_add(ll,ll+rr>>1,k<<1);
		_add((ll+rr>>1)+1,rr,k<<1|1);
		f[k]=f[k<<1]+lazy[k<<1]*(rr-ll+1)/2+f[k<<1|1]+lazy[k<<1|1]*(rr-ll+1)/2;
	}
	void add(int _l,int _r,int _v){
		l=_l;r=_r;v=_v;_add(0,SIZE-1,1);
	}
	int _query(int ll,int rr,int k){
		if(r<ll||rr<l)return 0;
		if(l<=ll&&rr<=r){
			return f[k]+lazy[k]*(rr-ll+1);
		}
		lazy[k<<1]+=lazy[k];lazy[k<<1|1]+=lazy[k];lazy[k]=0;
		int ret=_query(ll,ll+rr>>1,k<<1)+_query((ll+rr>>1)+1,rr,k<<1|1);
		f[k]=f[k<<1]+lazy[k<<1]*(rr-ll+1)/2+f[k<<1|1]+lazy[k<<1|1]*(rr-ll+1)/2;
		return ret;
	}
	int query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}seg;
struct range{
	int l,r,color;
	range(int a,int b,int c){l=a;r=b;color=c;}
};
bool operator<(range a,range b){
	return a.l<b.l;
}
set<range>S;
int myabs(int x){
	if(x<0)return -x;
	return x;
}
void show(){
	cerr<<"show---------------------\n";
	for(auto r:S){
		if(r.l!=r.r){
			cerr<<r.l<<" "<<r.r<<" "<<r.color<<endl;
		}
	}
	cerr<<"end----------------------\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)S.insert(range(i,i,i));
	while(m--){
		int type,l,r,x;
		cin>>type;
		if(type==1){
			cin>>l>>r>>x;
			auto itr=S.lower_bound(range(l,r,x));
			if(itr!=S.begin()&&prev(itr)->l<=l&&prev(itr)->r>=r){
				itr--;
				range ins1=*itr;ins1.r=l-1;
				range ins2=range(l,r,x);
				range ins3=*itr;ins3.l=r+1;
				seg.add(l,r,myabs(x-itr->color));
				S.erase(itr);
				if(ins1.r>=ins1.l)S.insert(ins1);
				if(ins2.r>=ins2.l)S.insert(ins2);
				if(ins3.r>=ins3.l)S.insert(ins3);
				continue;
			}
			if(itr!=S.begin()&&prev(itr)->r>=l){
				auto pre=prev(itr);
				seg.add(l,pre->r,myabs(pre->color-x));
				range ins=*pre;ins.r=l-1;
				S.erase(pre);
				S.insert(ins);
			}
			while(itr!=S.end()&&itr->r<=r){
				seg.add(itr->l,itr->r,myabs(x-itr->color));
				S.erase(itr++);
			}
			if(itr!=S.end()&&itr->l<=r){
				range ins=*itr;
				seg.add(ins.l,r,myabs(ins.color-x));
				ins.l=r+1;
				S.erase(itr);
				S.insert(ins);
			}
			S.insert(range(l,r,x));
		}else{
			cin>>l>>r;
			cout<<seg.query(l,r)<<endl; 
		}
	}
	return 0;
}