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
//A^X=B,C^X=D,A^C=B^D
int main()
{
	printf("?");for(int i=1;i<=100;i++) printf(" %d",i);
	putchar('\n'),fflush(stdout);int B;read(B);
	printf("?");for(int i=1;i<=100;i++) printf(" %d",i*128);
	putchar('\n'),fflush(stdout);int D;read(D);
	int AC=B^D,A=AC&127;printf("! %d\n",A^B),fflush(stdout);
	return 0;
}