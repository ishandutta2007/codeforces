#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
queue<int> qx,qy,qt;
map<int,bool> Map;
int a[MaxN],b[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n,Map.clear();
		rep(i,1,n)
			cin>>a[i],Map[a[i]]^=true;
		bool Flag=true;
		rep(i,1,n) if(Map[a[i]]) Flag=false;
		if(!Flag)
			{cout<<"-1\n";continue;}
		int m=n,p=1;
		int cnt=0,cnt_0=0;
		while(p<=m)
		{
			int q;
			rep(i,p+1,m)
			{
				if(a[i]==a[p])
				{
					q=i;
					break;
				}
			}
			rep(i,0,q-p-2)
				++cnt,qx.push(q+i),qy.push(a[p+1+i]);
			rep(i,0,q-p-2)
				b[i+1]=b[((q-p-1)<<1)-i]=a[p+1+i];
			dow(i,m,q+1)
				a[i+((q-p-1)<<1)]=a[i];
			m+=((q-p-1)<<1);
			rep(i,1,((q-p-1)<<1))
				a[q+i]=b[i];
			qt.push((q-p)<<1),++cnt_0;
			p+=((q-p)<<1);
		}
		cout<<cnt<<'\n';
		while(!qx.empty())
		{
			cout<<qx.front()<<' '<<qy.front()<<'\n';
			qx.pop(),qy.pop();
		}
		cout<<cnt_0<<'\n';
		while(!qt.empty())
			cout<<qt.front()<<' ',qt.pop();
		cout<<'\n';
	}
	return 0;
}