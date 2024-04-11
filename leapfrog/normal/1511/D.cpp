//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,K,St;string rs,s[26][26],S[100005];
inline string pls(string a,string b) {if(a[a.size()-1]==b[0]) return a+b[1];else return a+b;}
int main()
{
	read(n),read(K);
	if(K==1) {for(int i=1;i<=n;i++) putchar('a');return putchar('\n'),0;}
	for(int i=0;i<K;i++) for(int j=i;j<K;j++) s[i][j]=char(i+'a'),s[i][j]=s[i][j]+char(j+'a');
	for(int i=0;i<K;i++) for(int j=i;j<K;j++) S[++St]=s[i][j];
	for(int i=1;i<=St;i++) rs=pls(rs,S[i]);
	int len=rs.size();for(int i=0;i<n;i++) putchar(rs[i%len]);
	return putchar('\n'),0;
}