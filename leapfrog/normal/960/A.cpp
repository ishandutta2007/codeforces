//Coded by Kamiyama_Shiki on 2021.11.10 {{{
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
int n;char ch[5005];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	int d1=1;if(ch[d1]!='a') return puts("NO"),0;
	while(ch[d1+1]=='a') d1++;
	int d2=d1+1;if(ch[d2]!='b') return puts("NO"),0;
	while(ch[d2+1]=='b') d2++;
	int d3=d2+1;if(ch[d3]!='c') return puts("NO"),0;
	while(ch[d3+1]=='c') d3++;
	if(d3!=n) return puts("NO"),0;
	if(d3-d2==d2-d1||d3-d2==d1) return puts("YES"),0;
	return puts("NO"),0;
}