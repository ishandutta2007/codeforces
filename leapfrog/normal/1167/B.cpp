//Coded by leapfrog on 2021.10.27 {{{
//
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
const int v[6]={4,8,15,16,23,42};
inline int qry(int x,int y)
{
	printf("? %d %d\n",x,y);fflush(stdout);
	int w;read(w);return w;
}
int main()
{
	int a=qry(1,2),b=qry(3,4),c=v[0]*v[1]*v[2]*v[3]*v[4]*v[5]/a/b;
	int a1=qry(1,1),a2=qry(3,5),rs[6];
	rs[0]=sqrt(a1)+1e-8,rs[1]=a/rs[0];
	for(int i=0;i<6;i++) for(int j=0;j<6;j++) for(int k=0;k<6;k++)
		if(i^j&&i^k&&j^k&&v[i]*v[j]==b&&v[i]*v[k]==a2) rs[2]=v[i],rs[3]=v[j],rs[4]=v[k];
	rs[5]=c/rs[4],printf("! ");for(int i=0;i<6;i++) printf("%d ",rs[i]);
	return putchar('\n'),fflush(stdout),0;
}