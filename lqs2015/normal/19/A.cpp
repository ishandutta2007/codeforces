#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct team
{
	string nam;
	int sc,jsq,jq;
}T[111];
int n,x,y,j;
char c;
string ans[111],s,a,b;
void add(string &s,int x,int y)
{
	for (int i=1;i<=n;i++)
	{
		if (T[i].nam==s)
		{
			if (x>y) T[i].sc+=3;
			else if (x==y) T[i].sc++;
			T[i].jsq+=(x-y);
			T[i].jq+=x;
		}
	}
}
bool cmp(team i,team j)
{
	if (i.sc!=j.sc) return i.sc>j.sc;
	if (i.jsq!=j.jsq) return i.jsq>j.jsq;
	return i.jq>j.jq;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>T[i].nam;
	for (int i=1;i<=(n-1)*n/2;i++)
	{
		cin>>s;
		cin>>x>>c>>y;
		for (j=0;j<s.size();j++)
		if (s[j]=='-') break;
		a=s.substr(0,j);
		b=s.substr(j+1);
		add(a,x,y);
		add(b,y,x);
	}
	sort(T+1,T+n+1,cmp);
	for (int i=1;i<=n/2;i++) ans[i]=T[i].nam;
	sort(ans+1,ans+n/2+1);
	for (int i=1;i<=n/2;i++) cout<<ans[i]<<endl;
	return 0;
}