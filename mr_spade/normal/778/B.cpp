#include<cstdio>
#include<cctype>
#include<iostream>
#include<string>
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
const int N=5005,M=1005;
int n,m;
string emp;
struct var
{
	string name;
	string v1,op,v2;
	int n1,o,n2;
}v[N];
bool bit[N],ans1[M],ans2[M];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int cnt1,cnt2;
	bool flag=0,x,y;
	register int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		if(!flag)
			cin>>v[i].name;
		else
			v[i].name=emp;
		flag=0;
		cin>>emp;
		cin>>v[i].v1;
		cin>>emp;
		if(islower(emp[0]))
		{
			v[i].op=v[i].v2="";
			flag=1;
			continue;
		}
		v[i].op=emp;
		cin>>v[i].v2;
	}
	for(i=1;i<=n;i++)
	{
		if(islower(v[i].v1[0]))
		{
			for(j=1;j<=n;j++)
				if(v[j].name==v[i].v1)
					v[i].n1=j;
		}
		else if(v[i].v1[0]=='?')
			v[i].n1=n+1;
		if(v[i].op.size())
		{
			if(v[i].op[0]=='A')
				v[i].o=1;
			else if(v[i].op[0]=='O')
				v[i].o=2;
			else
				v[i].o=3;
		}
		if(v[i].v2.size()&&islower(v[i].v2[0]))
		{
			for(j=1;j<=n;j++)
				if(v[j].name==v[i].v2)
					v[i].n2=j;
		}
		else if(v[i].v2.size()&&v[i].v2[0]=='?')
			v[i].n2=n+1;
	}
	for(i=0;i<m;i++)
	{
		cnt1=cnt2=0;
		bit[n+1]=0;
		for(j=1;j<=n;j++)
		{
			if(v[j].n1)
				x=bit[v[j].n1];
			else
				x=v[j].v1[i]-'0';
			if(v[j].n2)
				y=bit[v[j].n2];
			else
				y=(v[i].o?v[j].v2[i]-'0':0);
			switch(v[j].o)
			{
				case 0:bit[j]=x;break;
				case 1:bit[j]=x&y;break;
				case 2:bit[j]=x|y;break;
				case 3:bit[j]=x^y;break;
			}
			if(bit[j])
				cnt1++;
		}
		bit[n+1]=1;
		for(j=1;j<=n;j++)
		{
			if(v[j].n1)
				x=bit[v[j].n1];
			else
				x=v[j].v1[i]-'0';
			if(v[j].n2)
				y=bit[v[j].n2];
			else
				y=(v[i].o?v[j].v2[i]-'0':0);
			switch(v[j].o)
			{
				case 0:bit[j]=x;break;
				case 1:bit[j]=x&y;break;
				case 2:bit[j]=x|y;break;
				case 3:bit[j]=x^y;break;
			}
			if(bit[j])
				cnt2++;
		}
		if(cnt1<cnt2)
			ans1[i]=0,ans2[i]=1;
		else if(cnt1>cnt2)
			ans1[i]=1,ans2[i]=0;
		else
			ans1[i]=ans2[i]=0;
	}
	for(i=0;i<m;i++)
		cout<<(char)(ans1[i]+'0');
	cout<<endl;
	for(i=0;i<m;i++)
		cout<<(char)(ans2[i]+'0');
	cout<<endl;
	return 0;
}