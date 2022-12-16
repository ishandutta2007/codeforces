#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;
int add(int a,int b){
	return (a+b)%MOD;
}
void plu(int &a,int b){
	a=add(a,b);
}
int sub(int a,int b){
	return (a-b+MOD)%MOD;
}
int mul(int a,int b){
	return (LL)a*b%MOD;
}
int mul(int a,int b,int c){
	return mul(mul(a,b),c);
}
int sqr(int x){
	return mul(x,x);
}
int ksm(int a,int b){
	return b==0?1:mul(sqr(ksm(a,b>>1)),b&1?a:1);
}
int inv(int a){
	return ksm(a,MOD-2);
}
const int N=100100;
int n;
int x[N],v[N],p[N][2];
struct X{
	int v[2][2];
};
struct SegTree{
	X val[4*N];
#define TR int l,int r,int id
#define M int mid=(l+r)>>1
#define L l,mid,id<<1
#define R mid+1,r,(id<<1)|1
#define F(x) for(int x=0;x<2;x++)
	void upd(int id,int mid){
		F(i)F(j){
			val[id].v[i][j]=0;
		}
		F(i)F(j)F(k){
			plu(
				val[id].v[i][j],
				mul(val[id<<1].v[i][k],val[(id<<1)|1].v[k][j],p[mid+1][k])
			);
		}
	}
	void build(TR){
		if(l==r){
			F(i)F(j){
				val[id].v[i][j]=1;
			}
			return;
		}
		M;
		build(L);
		build(R);
		upd(id,mid);
	}
	void set(int x,const X &v,TR){
		//if(id==1)// cerr<<"set "<<x<<" "<<i<<" "<<j<<" "<<v<<endl;
		if(l==r){
			val[id]=v;
			return;
		}
		M;
		if(x<=mid){
			set(x,v,L);
		}
		else{
			set(x,v,R);
		}
		upd(id,mid);
	}
	const X &get(int x,TR){
		//if(id==1)// cerr<<"get "<<x<<" "<<i<<" "<<j<<endl;
		if(l==r){
			return val[id];
		}
		M;
		if(x<=mid){
			return get(x,L);
		}
		else{
			return get(x,R);
		}
	}
	int query(){
		int ans=0;
		F(i)F(j){
			plu(ans,mul(p[1][i],val[1].v[i][j],p[n][j]));
		}
		// cerr<<"q "<<ans<<endl;
		return ans;
	}
};
const int INV2=inv(2);
const int INV100=inv(100);
struct E{
	int id,i,j,ta,tb;
	bool operator<(const E o)const{
		return (LL)ta*o.tb<(LL)o.ta*tb;
	}
};
typedef vector<E> VE;
VE evs;
SegTree t;
#define T 1,n-1,1
void ae(int x,int i,int j){
	int y=x+1;
	int dv=i!=j?v[x]+v[y]:abs(v[x]-v[y]);
	int s=::x[y]-::x[x];
	// cerr<<"ae "<<x<<" "<<i<<" "<<j<<" "<<s<<"/"<<dv<<endl;
	evs.push_back({x,i,j,s,dv});
}
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("0");
		exit(0);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&v[i],&p[i][1]);
		p[i][0]=100-p[i][1];
	}
	t.build(T);
	for(int i=1;i<=n-1;i++){
		ae(i,1,0);
		if(v[i]<v[i+1]){
			ae(i,0,0);
		}
		if(v[i]>v[i+1]){
			ae(i,1,1);
		}
	}
	sort(evs.begin(),evs.end());
	int ans=0;
	for(VE::iterator it=evs.begin();it!=evs.end();it++){
		int dt=mul(it->ta%MOD,inv(it->tb%MOD));
		// cerr<<"t = "<<dt<<" ("<<it->ta<<"/"<<it->tb<<")"<<endl;
		X tmp1;
		tmp1=t.get(it->id,T);
		X tmp2;
		memset(&tmp2,0,sizeof(tmp2));
		swap(
			tmp2.v[it->i][it->j],
			tmp1.v[it->i][it->j]
		);
		t.set(it->id,tmp2,T);
		int cb=mul(t.query(),dt);
		plu(ans,cb);
		t.set(it->id,tmp1,T);
	}
	ans=mul(ans,ksm(INV100,n));
	printf("%d\n",ans);
	return 0;
}