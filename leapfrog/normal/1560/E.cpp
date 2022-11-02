#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
char ch[500005],rs[500005];int n,cn[26],rt;
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1),memset(cn,0,sizeof(cn)),rt=0;
	for(int i=n;i>=1;cn[ch[i]-'a']++,i--) if(!cn[ch[i]-'a']) rs[++rt]=ch[i];
	reverse(rs+1,rs+rt+1);int vl=0;
	for(int i=1;i<=rt;i++) vl+=cn[rs[i]-'a']/i;
	if(vl>n) return puts("-1"),void();
	string ans,nw,ck;for(int i=1;i<=vl;i++) ans+=ch[i],nw+=ch[i];
	for(int i=1;i<=rt;i++)
	{
		ck+=nw;string de;
		for(int j=0;j<(int)nw.size();j++) if(nw[j]!=rs[i]) de+=nw[j];
		nw=de;
	}if((int)ck.size()!=n) return puts("-1"),void();
	for(int i=1;i<=n;i++) if(ck[i-1]!=ch[i]) return puts("-1"),void();
	cout<<ans<<" ";for(int i=1;i<=rt;i++) putchar(rs[i]);
	cout<<endl;
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}