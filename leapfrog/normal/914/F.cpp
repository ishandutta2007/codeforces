//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,Q;bitset<100005>bt[26],rs;char ch[100005],s[100005];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) bt[ch[i]-'a'][i]=1;
	read(Q);for(int op,l,r;Q--;)
	{
		read(op),read(l);if(op&1) scanf("%s",s);else read(r),scanf("%s",s+1);
		if(op&1) {bt[ch[l]-'a'][l]=0,bt[*s-'a'][l]=1,ch[l]=*s;continue;}
		rs.set();int ln=strlen(s+1);for(int i=1;i<=ln;i++) rs&=bt[s[i]-'a']>>(i-1);
		int la=(rs>>l).count(),ra=(rs>>(r-ln+2)).count();printf("%d\n",max(0,la-ra));
	}
	return 0;
}