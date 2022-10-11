#include <iostream>
#include <stack>
using namespace std;
struct bracket{
	int i,l,r;
};
bracket make(int ii,int ll,int rr)
{
	bracket tmp;
	tmp.i=ii;
	tmp.l=ll;
	tmp.r=rr;
	return tmp;
}
int main()
{
	int n;
	scanf("%d",&n);
	string s="";
	stack<bracket> st;
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		st.push(make(s.size(),l,r));
		s+='(';
		while (s.size()-st.top().i>=st.top().l && s.size()-st.top().i<=st.top().r)
		{
			st.pop();
			s+=')';
			if (st.empty())
			break;
		}
	}
	if (!st.empty())
	puts("IMPOSSIBLE");
	else
	puts(s.c_str());
}