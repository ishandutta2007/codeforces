//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct sam{int fa,len,ch[2];}S[1000005];int sls,smt,qw[1000005],sa[1000005];vector<int>v[1000015];
int n,s[500005],mn[500005][25],lg[500005],edp[1000005];char c[500005];long long res=0;const int N=500005;
inline void saminit() {sls=smt=1,S[0].ch[0]=S[0].ch[1]=0;}
inline void samins(int c)
{
	int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[p].len+1==S[q].len) return(void)(S[np].fa=q);
	int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void samsort()
{
	for(int i=1;i<=smt;i++) qw[S[i].len]++;
	for(int i=1;i<=n;i++) qw[i]+=qw[i-1];
	for(int i=1;i<=smt;i++) sa[qw[S[i].len]--]=i;
}
inline int gtmn(int l,int r) {int g=lg[r-l+1];return min(mn[l][g],mn[r-(1<<g)+1][g]);}
int main()
{
	read(n),scanf("%s",c+1),lg[0]=-1,saminit(),memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++) s[i]=s[i-1]+((c[i]=='(')<<1)-1,lg[i]=lg[i>>1]+1,v[s[i]+N].push_back(i);
	for(int i=n,p=1;i;i--) samins(c[i]==')'),p=S[p].ch[c[i]==')'],edp[p]=i,mn[i][0]=s[i];
	for(int j=1;j<20;j++) for(int i=1;i+(1<<j)-1<=n;i++) mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
	samsort();for(int z=smt,i=sa[z];z;z--,i=sa[z]) if(!edp[S[i].fa]) edp[S[i].fa]=edp[i];
	for(int i=2;i<=smt;i++)
	{
		int le=edp[i]+S[S[i].fa].len,ri=edp[i]+S[i].len-1,L=edp[i],md,R=le,rs=le-1;
		//printf("%d ~ %d : %d ",le,ri,L);
		while(le<=ri)
		{
			md=(le+ri)>>1;
			if(gtmn(L,md)-s[L-1]>=0) rs=md,le=md+1;else ri=md-1;
		}
		//printf("%d\n",rs);
		if(rs<R) continue;
		res+=upper_bound(v[s[L-1]+N].begin(),v[s[L-1]+N].end(),rs)-lower_bound(v[s[L-1]+N].begin(),v[s[L-1]+N].end(),R);
	}
	return printf("%lld\n",res),0;
}