#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=200005;int n,ct,a[N],cn[N],cl[N],ls[N],nx[N],cnt=0;
char v[N];priority_queue<pair<int,int> >q;
inline void ers(int x) {ls[nx[x]]=ls[x],nx[ls[x]]=nx[x],v[x]=1;}
int main()
{
	read(n);for(int i=n;i;i--) read(a[i]);
	for(int i=1;i<=n;i++) if(a[i]^a[i-1]) cn[++ct]=1,cl[ct]=a[i];else ++cn[ct];
	for(int i=1;i<=ct;i++) ls[i]=i-1,nx[i]=i+1,q.push(make_pair(cn[i],i));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();if(v[x]) continue;else cnt++;
		int l=ls[x],r=nx[x];ers(x);if(l&&cl[l]==cl[r]) cn[l]+=cn[r],q.push(make_pair(cn[l],l)),ers(r);
	}
	return printf("%d\n",cnt),0;
}