//{{{
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
const int N=2005;set<pair<int,int> >st;
set<pair<int,int> >rs;bitset<2005>bt[N],tp,ful;int n,m,Q;
inline void ins(int a,int b) {rs.insert(make_pair(min(a,b),max(a,b)));}
inline void ers(int a,int b) {rs.erase(make_pair(min(a,b),max(a,b)));}
inline char chk(bitset<2005>&a,bitset<2005>&b) {return a!=(a&b);}//a<b
int main()
{
	read(n,m,Q);for(int i=1;i<=n;i++) st.insert(make_pair(0,i));
	ful.set();for(int wh,l,r;Q--;)
	{
		tp=ful,read(wh,l,r),tp>>=(N-r+l-1),tp<<=l;
		int sz=bt[wh].count();auto it=st.lower_bound(make_pair(sz,wh));
		if(it!=st.begin())
		{
			auto jt=it;jt--;int x=it->second,y=jt->second;
			if(chk(bt[y],bt[x])) ers(x,y);
		}
		if(it!=--st.end())
		{
			auto jt=it;jt++;int x=it->second,y=jt->second;
			if(chk(bt[x],bt[y])) ers(x,y);
		}
		if(it!=st.begin()&&it!=--st.end())
		{
			auto at=it,jt=it;at--,jt++;int x=at->second,y=jt->second;
			if(chk(bt[x],bt[y])) ins(x,y);
		}
		st.erase(make_pair(sz,wh)),bt[wh]^=tp;
		sz=bt[wh].count(),st.insert(make_pair(sz,wh));
		it=st.lower_bound(make_pair(sz,wh));
		if(it!=st.begin()&&it!=--st.end())
		{
			auto at=it,jt=it;at--,jt++;int x=at->second,y=jt->second;
			if(chk(bt[x],bt[y])) ers(x,y);
		}
		if(it!=st.begin())
		{
			auto jt=it;jt--;int x=it->second,y=jt->second;
			if(chk(bt[y],bt[x])) ins(x,y);
		}
		if(it!=--st.end())
		{
			auto jt=it;jt++;int x=it->second,y=jt->second;
			if(chk(bt[x],bt[y])) ins(x,y);
		}
		if(rs.empty()) {puts("-1");continue;}
		int x=rs.begin()->first,y=rs.begin()->second;
		int a=((bt[y]^bt[x])&bt[y])._Find_first();
		int b=((bt[y]^bt[x])&bt[x])._Find_first();
		printf("%d %d %d %d\n",x,min(a,b),y,max(a,b));
	}return 0;
}