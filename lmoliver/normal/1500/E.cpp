#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=2.1e5;
const int Q=2.1e5;

LL nums[N+Q];
int numc=0;
int numid(LL v){
	return lower_bound(nums,nums+numc,v)-nums;
}

LL s[N];
int op[Q];
LL a[Q];

struct Sumer{
	int cnt;
	LL sum;
	LL tot;
};
Sumer operator+(Sumer l,Sumer r){
	return (Sumer){l.cnt+r.cnt,l.sum+r.sum,l.tot+r.tot+l.cnt*r.sum};
}

template<class T>
struct BIT{
	static const int S=N+Q;
	T a[S];
	T tot;
	void add(int x,T v){
		x++;
		for(;x<S;x+=x&-x)a[x]+=v;
		tot+=v;
	}
	T query(int x)const{
		x++;
		LL ans=0;
		for(;x;x&=x-1)ans+=a[x];
		return ans;
	}
	int kth(T sum)const{
		if(!sum)return -1;
		if(sum>tot)return INT_MAX;
		int ans=0;
		R(l,19,0){
			int t=ans+(1<<l);
			if(t<S&&a[t]<sum){
				sum-=a[t];
				ans=t;
			}
		}
		ans++;
		return ans-1;
	}
};
BIT<int> cnt;

struct SegTree{
	static const int S=N+Q;
	Sumer val[4*S];
	void edit(int x,const Sumer &v,int ll,int rr,int id){
		// cerr<<"edit "<<x<<" "<<v.sum<<" ["<<ll<<","<<rr<<"] id="<<id<<endl;
		if(ll==rr)val[id]=v;
		else{
			int mid=(ll+rr)>>1;
			if(x<=mid)edit(x,v,ll,mid,id*2);
			else edit(x,v,mid+1,rr,id*2+1);
			val[id]=val[id*2]+val[id*2+1];
		}
	}
	void edit(int x,Sumer v){
		edit(x,v,0,numc-1,1);
	}
	Sumer query(int l,int r,int ll,int rr,int id)const{
		if(l<=ll&&r>=rr)return val[id];
		if(r<ll||rr<l)return (Sumer){0,0,0};
		int mid=(ll+rr)>>1;
		return query(l,r,ll,mid,id*2)+query(l,r,mid+1,rr,id*2+1);
	}
	Sumer query(int l,int r)const{
		return query(l,r,0,numc-1,1);
	}
	Sumer tot()const{
		return val[1];
	}
}tr;


void add(int id){
	// cerr<<"+ #"<<id<<" "<<nums[id]<<endl;
	cnt.add(id,1);
	tr.edit(id,(Sumer){1,nums[id],nums[id]});
}
void sub(int id){
	// cerr<<"- #"<<id<<" "<<nums[id]<<endl;
	cnt.add(id,-1);
	tr.edit(id,(Sumer){0,0,0});
}

LL f(int k){
	int id1=cnt.kth(k+1);
	int id2=cnt.kth(cnt.tot-k+1);
	// cerr<<nums[id1]<<" "<<(id2<numc?nums[id2]:-1)<<" ->";
	return tr.query(0,id1).sum-tr.query(id2,numc-1).sum;
}

LL query(){
	// cerr<<"query"<<endl;
	// cerr<<"s = ";
	// F(i,1,cnt.tot){
	// 	cerr<<tr.query(cnt.kth(i),cnt.kth(i)).sum<<" ";
	// }
	// cerr<<endl;
	// D(i,cnt.tot)cerr<<"f("<<i<<")="<<f(i)<<endl;
	int l=0,r=(cnt.tot-1)/2;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(f(mid)>=0)l=mid;
		else r=mid-1;
	}
	// cerr<<"l="<<l<<endl;
	int id1=cnt.kth(l+1);
	int id2=cnt.kth(cnt.tot-l+1);
	Sumer lp=tr.query(0,id1);
	// cerr<<"lp.sum="<<lp.sum<<" lp.tot="<<lp.tot<<endl;
	Sumer rp=tr.query(id2,numc-1);
	// cerr<<"rp.sum="<<rp.sum<<" rp.tot="<<rp.tot<<endl;
	LL ans=((l+2)*lp.sum-lp.tot)-rp.tot;
	// cerr<<"ans="<<ans<<endl;
	ans*=2;
	if(cnt.tot&1)ans-=max(f((cnt.tot-1)>>1),0LL);
	// cerr<<tr.tot().sum<<"-"<<ans<<endl;
	return tr.tot().sum-ans;
}

int main(){
	int n=read(),q=read();
	D(i,n){
		s[i]=read();
		nums[numc++]=s[i];
	}
	D(i,q){
		op[i]=read();
		a[i]=read();
		if(op[i]==1)nums[numc++]=a[i];
	}
	sort(nums,nums+numc);
	numc=unique(nums,nums+numc)-nums;
	D(i,n)add(numid(s[i]));
	printf("%lld\n",query());
	D(i,q){
		int aa=numid(a[i]);
		if(op[i]==1){
			add(aa);
		}
		else{
			sub(aa);
		}
		printf("%lld\n",query());
	}
	return 0;
}