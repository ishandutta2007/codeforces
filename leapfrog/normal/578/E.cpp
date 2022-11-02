//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=100005;int n;char ch[N];
vector<int>v[N<<1];int st=N-3;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	int md=st,l=st+1,r=st,dl=st,dr=st+1;
	for(int i=1;i<=n;i++)
		if(ch[i]=='L') if(r>md) v[++md].push_back(i);else v[--l].push_back(i);
		else if(l<=md) v[md--].push_back(i);else v[++r].push_back(i);
	printf("%d\n",r-l);int nw;// md  st 
	if(md-l+1>r-st) nw=dl--;else if(md-l+1<r-st) nw=dr++;// LL  RR
	else if(r-st>st-l+1) nw=dr++;else nw=dl--;
	for(int Kamiyama_Shiki=r-l+1;Kamiyama_Shiki--;)
	{
		for(size_t i=0;i<v[nw].size();i++) printf("%d ",v[nw][i]);
		if(nw>md) nw=dl--;else nw=dr++;
	}return putchar('\n'),0;
}