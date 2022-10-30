//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,tn[15],id[5],nm[15];char ch[1000005];
int main()
{
	id[1]=1,id[2]=6,id[3]=8,id[4]=9;
	do
	{
		int vl=0;for(int i=1;i<=4;i++) vl=10*vl+id[i];
		tn[vl%7]=vl;
	}while(next_permutation(id+1,id+5));
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) nm[ch[i]^48]++;
	nm[1]--,nm[6]--,nm[8]--,nm[9]--;
	int r=0;for(int i=1;i<10;i++) for(int j=1;j<=nm[i];j++) putchar(i^48),r=(10*r+i)%7;
	printf("%d",tn[(7-r*10000%7)%7]);
	for(int i=1;i<=nm[0];i++) putchar('0');
	return putchar('\n'),0;
}