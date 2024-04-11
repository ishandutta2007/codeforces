#include<bits/stdc++.h>
using namespace std;const int N=400008;
struct node{int len,fa,ch[26];}sm[N];
int n,m,smt=1,lst=1,s1[N],s2[N],mx=2e9;char c1[N>>2],c2[N>>2];
inline void upd(int x,int *sz) {while(x&&sz[x]<=1) sz[x]++,x=sm[x].fa;}
inline void ins(int c,int *sz)
{
	int p=lst,np=lst=++smt;sm[np].len=sm[p].len+1;
	for(;p&&!sm[p].ch[c];p=sm[p].fa) sm[p].ch[c]=np;
	int q=sm[p].ch[c];if(p==0) return(void)(sm[np].fa=1,upd(lst,sz));
	if(sm[q].len==sm[p].len+1) return(void)(sm[np].fa=q,upd(lst,sz));
	int nq=++smt;sm[nq]=sm[q],sm[nq].len=sm[p].len+1,sm[q].fa=sm[np].fa=nq;
	s1[nq]=s1[q],s2[nq]=s2[q];for(;p&&sm[p].ch[c]==q;p=sm[p].fa) sm[p].ch[c]=nq;
	upd(lst,sz);
}
int main()
{
	scanf("%s%s",c1+1,c2+1),n=strlen(c1+1),m=strlen(c2+1);
	lst=1;for(int i=1;i<=n;i++) ins(c1[i]-'a',s1);
	lst=1;for(int i=1;i<=m;i++) ins(c2[i]-'a',s2);
	for(int i=2;i<=smt;i++) if(s1[i]==1&&s2[i]==1) mx=min(mx,sm[sm[i].fa].len+1);
	if(mx<=1e9) return printf("%d\n",mx),0;else return puts("-1"),0;
}