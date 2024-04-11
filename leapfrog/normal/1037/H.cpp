//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct sam{int fa,len,ch[26];}S[200005];int St=1,lst=1;
struct seg{int ls,rs;}t[5000005];int rt[200005],tt;
int n,Q,nxt[200005],qwq[200005],sa[200005];char c[100005];
inline void Motif(int &x,int l,int r,int dw)
{
	x?x:x=++tt;if(l==r) return;
	if(dw<=((l+r)>>1)) Motif(t[x].ls,l,(l+r)>>1,dw);else Motif(t[x].rs,((l+r)>>1)+1,r,dw);
}
inline int Query(int x,int l,int r,int dl,int dr)
{
	if(dl>r||l>dr||!x) return 0;else if(dl<=l&&r<=dr) return 1;
	return Query(t[x].ls,l,(l+r)>>1,dl,dr)|Query(t[x].rs,((l+r)>>1)+1,r,dl,dr);
}
inline int Merge(int x,int y,int l,int r)
{
	int v;if(!x||!y) return x|y;else if(!(x^y)) return x;else v=++tt;
	return t[v].ls=Merge(t[x].ls,t[y].ls,l,(l+r)>>1),t[v].rs=Merge(t[x].rs,t[y].rs,((l+r)>>1)+1,r),v;
}
inline void samins(int c)
{
	int p=lst,np=lst=++St;S[np].len=S[p].len+1,Motif(rt[np],1,n,S[np].len);
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[q].len==S[p].len+1) return(void)(S[np].fa=q);
	int nq=++St;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void Debug(int x,int l,int r) {if(!x);else if(l==r) printf("%d ",l);else Debug(t[x].ls,l,(l+r)>>1),Debug(t[x].rs,((l+r)>>1)+1,r);}
inline void sasrt()
{
	for(int i=1;i<=St;i++) ++qwq[S[i].len];
	for(int i=1;i<=n;i++) qwq[i]+=qwq[i-1];
	for(int i=1;i<=St;i++) sa[qwq[S[i].len]--]=i;
	for(int i=St;i;i--) rt[S[sa[i]].fa]=Merge(rt[S[sa[i]].fa],rt[sa[i]],1,n);
}
int main()
{
	scanf("%s",c+1),n=strlen(c+1),read(Q);
	for(int i=1;i<=n;i++) samins(c[i]-'a');
	sasrt();for(int l,r;Q--;)
	{
		read(l),read(r),scanf("%s",c+1);int x=1;
		int i,m=strlen(c+1);for(i=1;;i++)
		{
			nxt[i]=-1;
			for(int v=max(c[i]-'a'+1,0);v<26;v++)
			{
				int y=S[x].ch[v];
				if(y&&Query(rt[y],1,n,l+i-1,r)) {nxt[i]=v;break;}
			}
			int y=i>m?0:S[x].ch[c[i]-'a'];
			if(!y||i==m+1||!Query(rt[y],1,n,l+i-1,r)) break;else x=y;
		}
		for(;i&&!~nxt[i];i--);
		if(!i) {puts("-1");continue;}
		for(int j=1;j<i;j++) putchar(c[j]);
		putchar(nxt[i]+'a'),putchar('\n');
	}
	return 0;
}