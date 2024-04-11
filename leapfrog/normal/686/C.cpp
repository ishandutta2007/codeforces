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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int main()
{
	int n,m;read(n,m);int la=1,lb=1;
	for(int i=7;i<n;i*=7,la++);
	for(int i=7;i<m;i*=7,lb++);
	if(la+lb>7) return puts("0"),0;
	int id[7]={0,1,2,3,4,5,6},rs=0;do
	{
		int r1=0,r2=0;
		for(int i=0;i<la;i++) r1=7*r1+id[i];
		for(int i=la;i<la+lb;i++) r2=7*r2+id[i];
		rs+=r1<n&&r2<m;
	}while(next_permutation(id,id+7));
	for(int i=1;i<=7-la-lb;i++) rs/=i;
	return printf("%d\n",rs),0;
}