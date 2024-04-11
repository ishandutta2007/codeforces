#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e5+100;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

const ULL seed=10007;
const int lim=10;
map<int,int>tot[N];
ULL pre[N],num[N],key[26];
char s[N],str[N];
int op[N],L[N],R[N],LEN[N];char *q[N];
ULL x[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	srand(time(NULL));
	scanf("%s",s+1);
	int n=strlen(s+1),m,id,i,k,len,t,l,r,p,Q,ans,all=0;char c,*cur=str;ULL h,H;
	for (i=0;i<26;i++) key[i]=rand();
	for (i=num[0]=1;i<=n;i++) pre[i]=pre[i-1]*seed+key[s[i]-'a'],num[i]=num[i-1]*seed;
	for (i=1,m=gi();i<=m;i++)
		if ((op[i]=gi())==1) {
			L[i]=gi();
			while ((c=getchar())<'a'||'z'<c);
			R[i]=c;
		} else {
			L[i]=gi(),R[i]=gi();
			q[i]=cur;scanf("%s",cur+1);
			LEN[i]=strlen(cur+1);
			for (h=0,t=1;t<=LEN[i];t++)
				h=h*seed+key[cur[t]-'a'];
			cur+=LEN[i];
			if (LEN[i]<=lim)
				x[++all]=h;
		}
	sort(x+1,x+1+all);
	all=unique(x+1,x+1+all)-x-1;
			
	for (len=0;len<lim;len++)
		for (i=len+1;i<=n;i++) {
			h=pre[i]-pre[i-len-1]*num[len+1];
			k=lower_bound(x+1,x+1+all,h)-x;
			if (x[k]==h)
				for (t=i-len;t<=n;t+=t&-t)
					++tot[t][k];
		}
	for (id=1;id<=m;id++)
		if (op[id]==1) {
			k=L[id],c=R[id];
			for (l=max(1,k-lim+1);l<=k;l++) {
				h=0;
				for (r=l;r<=n&&r-l<lim;r++) {
					h=h*seed+key[s[r]-'a'];
					if (r>=k) {
						p=lower_bound(x+1,x+1+all,h)-x;
						if (x[p]==h)
							for (t=l;t<=n;t+=t&-t)
								tot[t][p]--;
					}
				}
			}
			s[k]=c;
			for (l=max(1,k-lim+1);l<=k;l++) {
				h=0;
				for (r=l;r<=n&&r-l<lim;r++) {
					h=h*seed+key[s[r]-'a'];
					if (r>=k) {
						p=lower_bound(x+1,x+1+all,h)-x;
						if (x[p]==h)
							for (t=l;t<=n;t+=t&-t)
								tot[t][p]++;
					}
				}
			}
		} else {
			l=L[id],r=R[id];ans=0;
			Q=LEN[id];
			h=0;for (i=1;i<=Q;i++) h=h*seed+key[q[id][i]-'a'];
			if (Q<=lim) {
				k=lower_bound(x+1,x+1+all,h)-x;
				if (x[k]==h) {
					r-=Q-1;
					for (t=r;t;t^=t&-t) ans+=tot[t][k];
					for (t=l-1;t;t^=t&-t) ans-=tot[t][k];
				}
			} else {
				H=0;
				for (i=l;i<=l+Q-1;i++) H=H*seed+key[s[i]-'a'];
				for (i=l+Q-1;i<=r;) {
					ans+=H==h;
					H=H*seed+key[s[++i]-'a'];
					H-=key[s[i-Q]-'a']*num[Q];
				}
			}
			printf("%d\n",ans);
		}
	return 0;
}