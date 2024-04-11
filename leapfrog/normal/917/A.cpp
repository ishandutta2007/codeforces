//Coded by Kamiyama_Shiki on 2021.11.09 {{{
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
const int N=5005;
int n;char ch[N];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);int rs=0;
	for(int l=1;l<=n;l++)
	{
		int sm=0,cn=0;
		for(int r=l;r<=n;r++)
		{
			if(ch[r]=='(') sm++;
			else if(ch[r]==')') {if(sm) sm--;else if(cn) cn--,sm++;else break;}
			else if(sm) sm--,cn++;else sm++;
			rs+=(sm==0);
		}
	}
	return printf("%d\n",rs),0;
}