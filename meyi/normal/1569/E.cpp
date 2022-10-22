#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int mod=998244353;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
    inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
    inline modint &operator^=(int k){
        modint ret=1,tmp=*this;
        for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
        return val=ret.val,*this;
    }
    inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
    inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
    inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
    inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi ap[33];
int h,k,m,n,nxt[17],pre[33];
inline vector<int> getrk(int l,int r,int bit,int f){
	queue<int>q;
	ri n=r-l+1,cnt=n;
	vector<int>ret(r+1);
	for(ri j=l;j<=r;++j)q.push(j);
	for(ri j=0;j<n-1;++j){
		ri p0=q.front();q.pop();
		ri p1=q.front();q.pop();
		if(bit&(1<<j))ret[p0]=pre[cnt],q.push(p1);
		else ret[p1]=pre[cnt],q.push(p0);
		--cnt;
	}
	ret[q.front()]=1;
	if(f)
		for(ri j=l;j<=r;++j)
			if(ret[j]>=f)
				ret[j]=nxt[ret[j]];
	return ret;
}
typedef pair<int,int> pii;
#define fi first
#define se second
inline vector<pii> calc(int l,int r,int f){
	ri n=r-l+1,all=(1<<(n-1))-1;
	vector<pii> ret;
	for(ri i=0;i<=all;++i){
		vector<int>rk=getrk(l,r,i,f);
		mi sum=0;
		for(ri j=l;j<=r;++j)sum+=j*ap[rk[j]];
		ret.push_back({sum.val,i});
	}
	sort(ret.begin(),ret.end());
	return ret;
}
inline void solve(vector<pii> v1,vector<pii> v2,int lf,int rf){
	for(auto i:v1){
		ri val=(h-i.fi+mod)%mod;
		auto j=lower_bound(v2.begin(),v2.end(),pii{val,0});
		if(j!=v2.end()&&j->fi==val){
			vector<int>rk1=getrk(1,m,i.se,lf),rk2=getrk(m+1,n,j->se,rf);
			for(ri l=1;l<=m;++l)printf("%d ",rk1[l]);
			for(ri l=m+1;l<=n;++l)printf("%d ",rk2[l]);
			exit(0);
		}
	}
}
int main(){
	ap[0]=1;
	pre[1]=1,pre[2]=2,pre[3]=3,pre[5]=5,pre[9]=9,pre[17]=17;
	nxt[1]=2,nxt[2]=3,nxt[3]=5,nxt[5]=9,nxt[9]=17;
	for(ri i=1;i<33;++i)
		if(!pre[i])
			pre[i]=pre[i-1];
	scanf("%d%d%d",&k,&ap[1],&h);
	n=1<<k,m=n>>1;
	for(ri i=1;i<=n;++i)ap[i]=ap[i-1]*ap[1];
	if(k<5){
		vector<pii>ans=calc(1,n,0);
		for(auto i:ans)
			if(i.fi==h){
				vector<int>rk=getrk(1,n,i.se,0);
				for(ri j=1;j<=n;++j)printf("%d ",rk[j]);
				return 0;
			}
	}
	else{
		solve(calc(1,m,1),calc(m+1,n,2),1,2);
		solve(calc(1,m,2),calc(m+1,n,1),2,1);
	}
	puts("-1");
	return 0;
}