#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3e4+9;
typedef pair<int,int>pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,c,q,a[N];

int C(int x,int y,int ret=1) {
	if(x<=1) return !y;
	if(x-1<y) return 0;
	per(i,x-1,x-y) ret*=i;
	rep(i,1,y) ret/=i;
	return ret;
}
int calc(int len,int c,int ret=0) {rep(i,0,c) ret=(ret+C(len,i)); return ret;}

int ql[9],qr[9],s[6][N],sw[6][N*10];
struct node {
	int l,r,w;
	node(int _l=0,int _r=0,int _w=0) {l=_l,r=_r,w=_w;}
} dq[6][N*10];
bool cmp(const node &x,const node &y) {return a[x.r]<a[y.r];}

node F(int p,int c,int k) {
	int lst=s[c][p];
	int l=lst+1,r=qr[c]-ql[c]+2;
	//cout<<p<<" "<<c<<" "<<l<<" "<<r<<endl;
	while(l<r) {
		int mid=(l+r)/2;
		//cout<<mid<<" "<<sw[c][mid]<<" "<<sw[c][lst]<<endl;
		if(sw[c][mid]-sw[c][lst]>=k) r=mid;
		else l=mid+1;
	}
	//cout<<p<<" "<<c<<" "<<k<<" "<<lst<<" "<<l<<endl;
	return node(dq[c][ql[c]+l-1].l,dq[c][ql[c]+l-1].r,sw[c][l-1]-sw[c][lst]);
}

signed main() {
	//freopen("CF1470E.in","r",stdin);
	//freopen("CF1470E.out","w",stdout);
	T=read();
	while(T--) {
		n=read(), c=read(), q=read();
		int lim=calc(n,c);
		rep(i,1,n) a[i]=read();
		//cerr<<"READ\n";
		rep(k,1,c) {
			ql[k]=12002,qr[k]=12001; rep(i,1,n) s[k][i]=0;
			dq[k][++qr[k]]=node(n,n,1);
			per(i,n-1,1) {
				int dl=0,dr=0;
				rep(j,1,min(k,n-i)) {
					if(a[i+j]<a[i]) dq[k][ql[k]-(++dl)]=node(i,i+j,calc(n-i-j,k-j)), s[k][i+1]++;
					else dq[k][qr[k]+(++dr)]=node(i,i+j,calc(n-i-j,k-j));
				}
				if(dl) sort(dq[k]+ql[k]-dl,dq[k]+ql[k],cmp), ql[k]-=dl;
				if(dr) sort(dq[k]+qr[k]+1,dq[k]+qr[k]+dr+1,cmp), qr[k]+=dr;
			}
			rep(i,1,n) s[k][i]=s[k][i-1]+s[k][i];
			rep(i,ql[k],qr[k]) sw[k][i-ql[k]+1]=sw[k][i-ql[k]]+dq[k][i].w;
			//rep(i,ql[k],qr[k]) cout<<sw[k][i-ql[k]+1]<<" "; puts("");
		}
		//cerr<<"PRED\n";
		//cerr<<lim<<endl;
		while(q--) {
			int pos=read(), k=read();
			if(k>lim) {puts("-1"); continue;}
			vector<pii>v;
			int p=1,rem=c,ok=k;
			while(rem&&p<=n) {
				node tmp=F(p,rem,k);
				v.push_back(pii(tmp.l,tmp.r));
				k-=tmp.w, rem-=(tmp.r-tmp.l), p=tmp.r+1;
				//cerr<<"** "<<tmp.l<<" "<<tmp.r<<" "<<tmp.w<<endl;
			}
			//if(T==0) cerr<<"PPD\n";
			bool flag=1;
			for(auto pp:v) {
				if(pp.fi<=pos&&pp.se>=pos) {
					flag=0;
					printf("%lld\n",a[pp.se+pp.fi-pos]);
					break;
				}
			} if(flag) printf("%lld\n",a[pos]);
			//if(T==0) cerr<<"EED\n";
		}
		//cerr<<"END\n";
	}
	return 0;
}