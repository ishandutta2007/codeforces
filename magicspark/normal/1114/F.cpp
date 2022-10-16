#include<bits/stdc++.h>
using namespace std;
char in[100005];
int iiter=0,llen=0;
inline char get(){
	if(iiter==llen)llen=fread(in,1,100000,stdin),iiter=0;
	if(llen==0)return EOF;
	return in[iiter++];
} 
inline int rd(){
	char ch=get();while(ch<'0'||ch>'9')ch=get();
	int res=0;while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=get();
	return res;
}
inline void pr(int res){
	if(res==0){putchar('0');return;}
	static int out[10];int len=0;
	while(res)out[len++]=res%10,res/=10;
	for(int i=len-1;i>=0;i--)putchar(out[i]+'0');
}
inline string getstr(){
	char ch=get();string res="";
	while(isspace(ch))ch=get();
	while(!isspace(ch))res+=ch,ch=get();
	return res;
}
#define int long long
const int N=4e5+10;
const int mod=1e9+7;
int n,q;
int a[N];
int id[310],p[65],tot=0;
long long num[310];
inline int ksm(int x,int k){
	if(k==0)return 1;
	int res=ksm(x,k>>1);
	res=1ll*res*res%mod;
	if(k&1)res=1ll*res*x%mod;
	return res;
}
class node{public:int val;long long msk;};
class SGT{
public:
	node ts[N<<2],tag[N<<2];
	int sz[N<<2];
	inline node pu(const node&A,const node&B){
		node res;
		res.val=1ll*A.val*B.val%mod;
		res.msk=A.msk|B.msk;
		return res;
	}
	void build(int x,int l,int r){
		if(l==r){
			ts[x]=(node){a[l],num[a[l]]};
			tag[x]=(node){1,0};
			sz[x]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		ts[x]=pu(ts[x<<1],ts[x<<1|1]);
		tag[x]=(node){1,0};
		sz[x]=sz[x<<1]+sz[x<<1|1];
	}
	inline void pd(int x){
		if(tag[x].val!=1){
			ts[x<<1].val=1ll*ts[x<<1].val*ksm(tag[x].val,sz[x<<1])%mod;
			ts[x<<1|1].val=1ll*ts[x<<1|1].val*ksm(tag[x].val,sz[x<<1|1])%mod;
			tag[x<<1].val=1ll*tag[x<<1].val*tag[x].val%mod;
			tag[x<<1|1].val=1ll*tag[x<<1|1].val*tag[x].val%mod;
			tag[x].val=1; 
		}
		if(tag[x].msk){
			ts[x<<1].msk=ts[x<<1].msk|tag[x].msk;
			ts[x<<1|1].msk=ts[x<<1|1].msk|tag[x].msk;
			tag[x<<1].msk=tag[x<<1].msk|tag[x].msk;
			tag[x<<1|1].msk=tag[x<<1|1].msk|tag[x].msk;
			tag[x].msk=0;
		}
	}
	void upd(int x,int l,int r,int cl,int cr,int val){
		if(l==cl&&r==cr){
//			if(l!=r)pd(x),ts[x]=pu(ts[x<<1],ts[x<<1|1]);
			ts[x].val=1ll*ts[x].val*ksm(val,sz[x])%mod;
			ts[x].msk=ts[x].msk|num[val];
			tag[x].val=1ll*tag[x].val*val%mod;
			tag[x].msk=tag[x].msk|num[val];
			return;
		}
		pd(x);
		int mid=(l+r)>>1;
		if(cr<=mid)upd(x<<1,l,mid,cl,cr,val);
		else if(mid+1<=cl)upd(x<<1|1,mid+1,r,cl,cr,val);
		else upd(x<<1,l,mid,cl,mid,val),upd(x<<1|1,mid+1,r,mid+1,cr,val);
		ts[x]=pu(ts[x<<1],ts[x<<1|1]);
	}
	node qry(int x,int l,int r,int cl,int cr){
		if(l==cl&&r==cr)return ts[x];
		pd(x);
		int mid=(l+r)>>1;node ret;
		if(cr<=mid)ret=qry(x<<1,l,mid,cl,cr);
		else if(mid+1<=cl)ret=qry(x<<1|1,mid+1,r,cl,cr);
		else ret=pu(qry(x<<1,l,mid,cl,mid),qry(x<<1|1,mid+1,r,mid+1,cr));
		ts[x]=pu(ts[x<<1],ts[x<<1|1]);return ret;
	}
}T;
signed main(){
	memset(p,-1,sizeof(p));
	memset(id,-1,sizeof(id));
	for(int i=2;i<=300;i++){
		bool ok=true;
		for(int j=2;j<i;j++)if(i%j==0)ok=false;
		if(ok)p[tot]=i,id[i]=tot++;
	}
	for(int i=2;i<=300;i++){
		int val=i;
		for(int j=0;j<tot;j++){
			int tmp=0;
			while(val%p[j]==0)tmp++,val/=p[j];
			if(tmp)num[i]|=1ll<<j;
//			if(tmp)cerr<<p[j]<<" "; 
		}
//		cerr<<endl; 
	}
	n=rd();q=rd();
	for(int i=0;i<n;i++)a[i]=rd();
	T.build(1,0,n-1);
	while(q--){
		string type=getstr();
		if(type[0]=='M'){
			int l=rd()-1,r=rd()-1,val=rd();
			T.upd(1,0,n-1,l,r,val);
		}else{
			int l=rd()-1,r=rd()-1;
			node res=T.qry(1,0,n-1,l,r);
			int val=res.val,tmp=1,ans=1,num=0;
			for(int i=0;i<tot;i++)if((res.msk>>i)&1){
				ans=1ll*ans*(p[i]-1)%mod;
			}
			tmp=1;
			for(int i=0;i<tot;i++)if((res.msk>>i)&1)tmp=1ll*tmp*p[i]%mod;
			ans=1ll*val*ksm(tmp,mod-2)%mod*ans%mod;
			pr(ans);
			putchar('\n');
		}
	}
	return 0;
}
/*inline? ll or int? size? min max?*/