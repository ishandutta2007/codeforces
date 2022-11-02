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
int T,n,a[500005],L[500005],R[500005];set<int>s;vector<int>rs;
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline void cut(int x) {R[L[x]]=R[x],L[R[x]]=L[x];}
inline void solve()
{
	read(n),s.clear(),rs.clear();for(int i=1;i<=n;i++) read(a[i]);
	if(n==1) return puts(a[1]^1?"0":"1 1"),void();
	for(int i=1;i<=n;i++) L[i]=i==1?n:i-1,R[i]=i==n?1:i+1;
	for(int i=1;i<=n;i++) if(gcd(a[i],a[R[i]])==1) s.insert(i);
	int nw=1;while(!s.empty())
	{
		set<int>::iterator it=s.lower_bound(nw);if(it==s.end()) it=s.begin();
		s.erase(R[*it]),rs.push_back(R[*it]);
		if(R[*it]==L[*it]) {a[*it]^1?void():rs.push_back(*it);break;}
		cut(R[*it]),nw=R[*it],s.erase(*it);if(gcd(a[nw],a[L[nw]])==1) s.insert(L[nw]);
	}
	printf("%d ",(int)rs.size());for(auto x:rs) printf("%d ",x);
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}