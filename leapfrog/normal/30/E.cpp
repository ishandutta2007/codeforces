//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct Hash
{
	typedef unsigned ull;ull hs1,hs2;
	inline char operator==(Hash b) const {return hs1==b.hs1&&hs2==b.hs2;}
	inline Hash operator+(Hash b) const {return(Hash){hs1+b.hs1,hs2+b.hs2};}
	inline Hash operator+(ull b) const {return(Hash){hs1+b,hs2+b};}
	inline Hash operator-(Hash b) const {return(Hash){hs1-b.hs1,hs2-b.hs2};}
	inline Hash operator*(Hash b) const {return(Hash){hs1*b.hs1,hs2*b.hs2};}
}bas={137ull,1145141ull},pw[100005],ph[100005],rh[100005];
int n,res=0,mx[100005],wh[100005],rc[100005];char a[100005];
inline Hash getp(int l,int r) {return ph[r]-ph[l-1]*pw[r-l+1];}
inline Hash getr(int l,int r) {return rh[l]-rh[r+1]*pw[r-l+1];}
int main()
{
	scanf("%s",a+1),n=strlen(a+1),pw[0]=(Hash){1ull,1ull};
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*bas,ph[i]=ph[i-1]*bas+a[i];
	for(int i=n;i;i--) rh[i]=rh[i+1]*bas+a[i];
	for(int i=1;i<=n;i++)
	{
		int le=0,ri=n-i+1,rs=0;
		while(le<=ri) {int md=(le+ri)>>1;if(getp(i,i+md-1)==getr(n-md+1,n)) rs=md,le=md+1;else ri=md-1;}
		if(mx[i+rs-1]<rs) mx[i+rs-1]=rs,wh[i+rs-1]=i;
	}
	for(int i=n;i;i--) if(mx[i]<mx[i+1]-1) wh[i]=wh[i+1],mx[i]=mx[i+1]-1;
	for(int i=1;i<=n;i++) if(mx[i]<mx[i-1]) mx[i]=mx[i-1],wh[i]=wh[i-1];
	//for(int i=1;i<=n;i++) printf("%d%c",mx[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
	{
		int le=0,ri=min(i-1,n-i),rs=0;
		while(le<=ri) {int md=(le+ri)>>1;if(getp(i-md,i)==getr(i,i+md)) rs=md,le=md+1;else ri=md-1;}
		res=max(res,rs+min(mx[i-rs-1],n-i-rs)),rc[i]=rs;
		//printf("%d%c",rs+min(mx[i-rs-1],n-i-rs),i==n?'\n':' ');
	}
	for(int i=1;i<=n;i++) if(res==rc[i]+min(mx[i-rc[i]-1],n-i-rc[i]))
	{
		if(min(mx[i-rc[i]-1],n-i-rc[i])) puts("3");else return printf("1\n%d %d\n",i-rc[i],rc[i]<<1|1),0;
		int qwq=min(mx[i-rc[i]-1],n-i-rc[i]);
		return printf("%d %d\n%d %d\n%d %d\n",wh[i-rc[i]-1],qwq,i-rc[i],rc[i]<<1|1,n-qwq+1,qwq),0;
	}
}