//meng meng da mjy >w<
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 200010
map<int,int>	L,R;
map<pair<int,int>,int>	M;
int n;
ll mjy=0;

int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		L[x]++;
		R[y]++;
		M[make_pair(x,y)]++;
	}
	for (map<int,int>::iterator it=L.begin();it!=L.end();it++)
	{
		ll sum=it->second;
		sum*=(it->second-1);
		sum/=2;
		mjy+=sum;
	}
	for (map<int,int>::iterator it=R.begin();it!=R.end();it++)
	{
		ll sum=it->second;
		sum*=(it->second-1);
		sum/=2;
		mjy+=sum;
	}
	for (map<pair<int,int>,int>::iterator it=M.begin();it!=M.end();it++)
	{
		ll sum=it->second;
		sum*=(it->second-1);
		sum/=2;
		mjy-=sum;
	}
	cout<<mjy<<endl;
	return 0;
}