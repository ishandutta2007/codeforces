//Coded by Kamiyama_Shiki on 2021.11.05 {{{
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
int n,tn[26];char ch[100005];
int main()
{
	read(n),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) tn[ch[i]-'a']++;
	for(int i=0;i<26;i++) if(tn[i]>1) return puts("Yes"),0;
	int cnt=0;for(int i=0;i<26;i++) cnt+=!!tn[i];
	return puts(cnt==1?"Yes":"No"),0;
}