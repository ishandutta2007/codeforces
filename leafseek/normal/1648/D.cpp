#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5,Bit=25,Limit=(1<<20);
constexpr int Infinity=(1LL<<62);
int a[MaxN],b[MaxN],c[MaxN],A[MaxN],B[MaxN];
int ql[MaxN],qr[MaxN],qw[MaxN],qwq[MaxN];
vector<int> Lit[Bit+1];
int Lit_Tot[Bit+1];
int Phi[MaxN<<2];
int AA[MaxN],BB[MaxN];
int F[MaxN];
inline void Solve_0(const int lvl,const int idx,const int L,const int R)
{
	if(L==R)
	{
		Phi[idx]=(max(A[L],F[L])+B[L]);
		return;
	}
	const int M=((L+R)>>1);
	Solve_0(lvl+1,idx<<1,L,M);
	Solve_0(lvl+1,idx<<1|1,M+1,R);
	AA[L]=max(A[L],F[L]);
	rep(i,L+1,R)
		AA[i]=max(AA[i-1],max(A[i],F[i]));
	BB[R]=B[R];
	dow(i,R-1,L)
		BB[i]=max(BB[i+1],B[i]);
	Phi[idx]=(-Infinity);
	rep(i,L,R-1)
		Phi[idx]=max(Phi[idx],AA[i]+BB[i+1]);
	Phi[idx]=max(Phi[idx],Phi[idx<<1]);
	Phi[idx]=max(Phi[idx],Phi[idx<<1|1]);
}
inline void Solve_1(const int lvl,const int zzz,const int L,const int R)
{
	rep(I,1,Lit_Tot[lvl])
	{
		const int idx=Lit[lvl][I];
		const int l=max(L,ql[idx]),r=min(R,qr[idx]);
		if(l==L&&r==R)
			qwq[idx]=max(qwq[idx],Phi[zzz]);
	}
	if(L==R) return;
	const int M=((L+R)>>1);
	AA[M]=max(A[M],F[M]);
	dow(i,M-1,L)
		AA[i]=max(AA[i+1],max(A[i],F[i]));
	BB[M+1]=B[M+1];
	rep(i,M+2,R)
		BB[i]=max(BB[i-1],B[i]);
	rep(I,1,Lit_Tot[lvl])
	{
		const int idx=Lit[lvl][I];
		const int l=max(L,ql[idx]),r=min(R,qr[idx]);
		if(l==L&&r==R) continue;
		if(l<=M&&r>M)
			qwq[idx]=max(qwq[idx],AA[l]+BB[r]);
	}
	Lit_Tot[lvl+1]=0,Lit[lvl+1].clear(),Lit[lvl+1].push_back(0);
	rep(I,1,Lit_Tot[lvl])
	{
		const int idx=Lit[lvl][I];
		const int l=max(L,ql[idx]),r=min(R,qr[idx]);
		if(l==L&&r==R) continue;
		if(l<=M) ++Lit_Tot[lvl+1],Lit[lvl+1].push_back(idx);
	}
	Solve_1(lvl+1,zzz<<1,L,M);
	Lit_Tot[lvl+1]=0,Lit[lvl+1].clear(),Lit[lvl+1].push_back(0);
	rep(I,1,Lit_Tot[lvl])
	{
		const int idx=Lit[lvl][I];
		const int l=max(L,ql[idx]),r=min(R,qr[idx]);
		if(l==L&&r==R) continue;
		if(r>M) ++Lit_Tot[lvl+1],Lit[lvl+1].push_back(idx);
	}
	Solve_1(lvl+1,zzz<<1|1,M+1,R);
}
struct Seg_Tree
{
	int Max[(Limit<<1)|5];
	inline void Initalize(void)
	{
		rep(i,1,(Limit<<1)-1) Max[i]=(-Infinity);
	}
	inline void Update(const int pos,const int wei)
	{
		int u=(Limit|pos);
		Max[u]=wei;
		while(u>>=1) Max[u]=max(Max[u<<1],Max[u<<1|1]);
	}
	inline int Query(const int lef,const int rig)
	{
		int Maxx=(-Infinity);
		for(int u=(Limit|(lef-1)),v=(Limit|(rig+1));u^v^1;u>>=1,v>>=1)
		{
			if(~u&1) Maxx=max(Maxx,Max[u^1]);
			if( v&1) Maxx=max(Maxx,Max[v^1]);
		}
		return Maxx;
	}
};
Seg_Tree St,St_A,St_B;
vector<int> vec[MaxN];
signed main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	rep(i,1,n) cin>>a[i],a[i]+=a[i-1];
	rep(i,1,n) cin>>b[i],b[i]+=b[i-1];
	rep(i,1,n) cin>>c[i],c[i]+=c[i-1];
	rep(i,1,n) A[i]=(a[i]-b[i-1]);
	rep(i,1,n) B[i]=(b[i]-c[i-1]);
	rep(i,1,q) cin>>ql[i]>>qr[i]>>qw[i],qwq[i]=(-Infinity);
	rep(I,0,Bit) Lit[I].push_back(0);
	rep(i,1,q) ++Lit_Tot[1],Lit[1].push_back(i);
	// Lef
	rep(i,1,n) vec[i].clear(),vec[i].push_back(0);
	rep(i,1,q) ++vec[qr[i]][0],vec[qr[i]].push_back(i);
	St.Initalize(),St_A.Initalize(),St_B.Initalize();
	rep(i,1,n) St_A.Update(i,A[i]),St_B.Update(i,B[i]);
	F[0]=(-Infinity);
	rep(i,1,n)
	{
		F[i]=(-Infinity);
		rep(I,1,vec[i][0])
		{
			const int idx=vec[i][I];
			const int l=ql[idx],r=qr[idx],w=qw[idx];
			F[i]=max(F[i],St_A.Query(l,i)-w);
			if(i>=2)
				F[i]=max(F[i],St.Query(max(1LL,l-1),i-1)-w);
		}
		St.Update(i,F[i]);
	}
	int Answer=(-Infinity);
	Solve_0(1,1,1,n);
	Solve_1(1,1,1,n);
	rep(i,1,q) qwq[i]=max(qwq[i],F[ql[i]-1]+St_B.Query(ql[i],qr[i]));
	rep(i,1,q) Answer=max(Answer,(qwq[i]-qw[i]));
	cout<<(c[n]+Answer)<<'\n';
	return 0;
}