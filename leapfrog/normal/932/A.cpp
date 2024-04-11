#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char K=getchar(),f=0;
    for(;K<48||K>57;K=getchar()) if(!(K^45)) f=1;
    for(;K>=48&&K<=57;K=getchar()) x=(x<<1)+(x<<3)+(K^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
char ch[1000005];
int main()
{
	scanf("%s",ch+1);int n=strlen(ch+1);
	printf("%s",ch+1),reverse(ch+1,ch+n+1);
	return printf("%s\n",ch+1),0;
}