//{{{
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
const int P=1000000007;set<int>s1,s2,st;int n,cnt=0;
int main()
{
	read(n),cnt=1;for(int i=1,x;i<=n;i++)
	{
		char ch[15];scanf("%s",ch),read(x);
		if(ch[1]=='D')
		{
			if(!s1.empty()&&x<*--s1.end()) {s1.insert(x);continue;}
			if(!s2.empty()&&x>*s2.begin()) {s2.insert(x);continue;}
			st.insert(x);continue;
		}
		if(!s1.empty()&&s1.count(x))
		{
			if(*--s1.end()!=x) return puts("0"),0;
			s1.erase(x);for(auto y:st) s2.insert(y);
			st.clear();continue;
		}
		if(!s2.empty()&&s2.count(x))
		{
			if(*s2.begin()!=x) return puts("0"),0;
			s2.erase(x);for(auto y:st) s1.insert(y);
			st.clear();continue;
		}
		cnt=(cnt+cnt)%P;
		for(auto y:st) if(y<x) s1.insert(y);else if(y>x) s2.insert(y);
		st.clear();
	}
	if(st.size()) cnt=1ll*cnt*((int)st.size()+1)%P;
	return printf("%d\n",cnt),0;
}