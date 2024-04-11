//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
char ch[10005];int n;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);int c[2]={0,0};
	for(int i=1;i<=n;i++) c[ch[i]>'Z']++;
	if(c[0]<=c[1]) {for(int i=1;i<=n;i++) if(ch[i]<='Z') ch[i]=ch[i]-'A'+'a';}
	else {for(int i=1;i<=n;i++) if(ch[i]>'Z') ch[i]=ch[i]-'a'+'A';}
	return printf("%s\n",ch+1),0;
}