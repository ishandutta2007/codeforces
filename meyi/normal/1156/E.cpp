#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ri int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    inline size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
gp_hash_table<int,vector<int>,custom_hash>cnt;
inline int query(int k,int l,int r){
	auto it=cnt.find(k);
	if(it==cnt.end())return 0;
	return upper_bound(it->second.begin(),it->second.end(),r)-lower_bound(it->second.begin(),it->second.end(),l);
}
int a[maxn],l[maxn],n,r[maxn],st[maxn],tp;
ll ans;
void solve(int p,int l,int r){
	if(!p||l>=r)return;
	if(p-l<r-p){
		for(ri i=l;i<=p;++i)ans+=query(a[p]-a[i],p,r);
	}
	else{
		for(ri i=p;i<=r;++i)ans+=query(a[p]-a[i],l,p);
	}
	solve(::l[p],l,p-1),solve(::r[p],p+1,r);
}
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		cnt[a[i]].push_back(i);
		while(tp&&a[i]>a[st[tp]])l[i]=st[tp--];
		if(tp)r[st[tp]]=i;
		st[++tp]=i;
	}
	solve(st[1],1,n);
	printf("%lld",ans);
	return 0;
}