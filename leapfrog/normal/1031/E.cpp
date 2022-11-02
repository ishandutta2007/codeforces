//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
struct out{int x,y,z;char operator<(out b) const {return x^b.x?x<b.x:(y^b.y?y<b.y:z<b.z);}};
int n;char a[100005];vector<out>rs,cg,tt;
inline void opt(int x,int y,int z) {a[x]^=1,a[y]^=1,a[z]^=1,rs.push_back((out){x,y,z});}
inline char dfs(vector<out>&cg,int nw,int lft,int L,int R)
{
	int cnt=0;for(int i=L;i<=R;i++) cnt+=a[i];
	if(cnt==0) return 1;else if(cnt>lft*3) return 0;
	if(nw==(int)cg.size()) return 0;
	if(dfs(cg,nw+1,lft,L,R)) return 1;
	a[cg[nw].x]^=1,a[cg[nw].y]^=1,a[cg[nw].z]^=1;
	if(dfs(cg,nw+1,lft-1,L,R)) return rs.push_back(cg[nw]),1;
	a[cg[nw].x]^=1,a[cg[nw].y]^=1,a[cg[nw].z]^=1;
	return 0;
}
inline void flush()
{
	puts("YES"),printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d %d %d\n",x.x,x.y,x.z);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	if(n<=8)
	{
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(j+j-i<=n) cg.push_back((out){i,j,j+j-i});
		if(dfs(cg,0,12+n/3,1,n)) return flush(),0;else return puts("NO"),0;
	}
	int l=1,r=n;for(l=1,r=n;l+8<=r;)
	{
		if(a[l]&&a[l+1]&&a[l+2]) opt(l,l+1,l+2),l+=3;
		else if(a[l]&&!a[l+1]&&a[l+2]) opt(l,l+2,l+4),l+=3;
		else if(a[l]&&!a[l+1]&&!a[l+2]) opt(l,l+3,l+6),l+=3;
		else if(!a[l]) l++;else if(!a[r]) r--;
		else if(a[r]&&a[r-1]&&a[r-2]) opt(r-2,r-1,r),r-=3;
		else if(a[r]&&!a[r-1]&&a[r-2]) opt(r-4,r-2,r),r-=3;
		else if(a[r]&&!a[r-1]&&!a[r-2]) opt(r-6,r-3,r),r-=3;
		else if((l+r)&1) opt(l,(l+r-1)>>1,r-1),opt(l+1,(l+r+1)>>1,r),l+=3,r-=3;
		else opt(l,(l+r)>>1,r),opt(l+1,(l+r)>>1,r-1),l+=3,r-=3;
	}
	{while(r-l+1<8&&l>1) l--;while(r-l+1<8&&r<n) r++;}
	for(int i=l;i<=r;i++) for(int j=i+1;j<=r;j++) if(j+j-i<=r) cg.push_back((out){i,j,j+j-i});
	if(dfs(cg,0,12,1,n)) return flush(),0;else return puts("NO"),0;
}