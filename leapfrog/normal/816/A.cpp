//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int hh,mm;
inline char chk(int x,int y) {return(x%10==y/10)&&(y%10==x/10);}
int main()
{
	read(hh),read(mm);int cnt=0;
	while(!chk(hh,mm)) {mm++,cnt++;if(mm==60) hh=(hh+1)%24,mm=0;}
	return printf("%d\n",cnt),0;
}