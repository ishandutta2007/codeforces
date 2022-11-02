//Coded by Kamiyama_Shiki on 2021.11.17 {{{
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
int n,a[200005],d[200005];priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	read(n);for(int i=1;i<n;i++) read(a[i]),d[a[i]]++;
	printf("%d\n",a[1]);for(int i=1;i<=n;i++) if(!d[i]) q.push(i);
	for(int i=n-1;i>=1;i--)
	{
		int x=q.top();q.pop(),printf("%d %d\n",a[i],x);
		if(!--d[a[i]]) q.push(a[i]);
	}return 0;
}