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
char ch[100005];int n,ct[26],cn;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) ct[ch[i]-'a']++;
	for(int i=0;i<26;i++) cn+=!!ct[i];
	if(cn<2||cn>4) return puts("No"),0;
	int fg=0;for(int i=0;i<26;i++) fg+=ct[i]>1;
	if(cn==2) return puts(fg>1?"Yes":"No"),0;
	if(cn==3) return puts(fg?"Yes":"No"),0;
	if(cn==4) return puts("Yes"),0;
}