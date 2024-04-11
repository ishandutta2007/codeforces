#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
map <string,string> var;
int n;

struct function
{
	string type;
	string name;
	int sum;
	string pr[10];
}func[5000];

int solve(string c)
{
	string name;
	int i;
	for(i=0;c[i]!='(';i++)
	{
		name+=c[i];
	}
	int sum=0;
	c[c.size()-1]=',';
	string pr[10];
	while(i!=c.size()-1)
	{
		for(i++;c[i]!=',';i++)
		{
			pr[sum]+=c[i];
		}
		sum++;
	}
	for(int i=0;i<sum;i++)
	{
		pr[i]=var[pr[i]];
	}
	int res=0;
	bool f=true;
	for(i=0;i<n;i++)
	{
		f=true;
		if(func[i].name!=name) continue;
		if(func[i].sum!=sum) continue;
		for(int j=0;j<sum;j++)
		{
			if(func[i].pr[j]=="T") continue;
			if(func[i].pr[j]!=pr[j]) f=false;
		}
		res+=f;
	}
	return res;
}

int main()
{
	int m,k;
	cin>>n;
	string c;
	rep(n)
	{
		cin>>func[i].type;
		cin>>c;
		int j;
		int st=0;
		for(j=0;j<=c.size();j++)
		{
			if(c[j]==' ')
			{
				st=j+1;
				continue;
			}
			if(c[j]=='(' || j==c.size())
			{
				func[i].name=c.substr(st,j-st);
				break;
			}
		}
		string now;
		while(c[c.size()-1]!=')')
		{
			cin>>now;
			c+=now;
		}
		for(j=0;c[j]!='(';j++);
		c[c.size()-1]=',';
		while(j!=c.size()-1)
		{
			int len=0;
			st=j+1;
			for(j++;c[j]!=',';j++)
			{
				len++;
			}
			func[i].pr[func[i].sum++]=c.substr(st,len);
		}
	}
	//---------------------------------------------------------------------
//	for(int i=0;i<n;i++)
//	{
//		cout<<func[i].name<<"  ";
//		for(int j=0;j<func[i].sum;j++)
//		{
//			cout<<func[i].pr[j]<<' ';
//		}
//		cout<<endl;
//	}
	//-----------------------------------------------------------------------------------
	cin>>m;
	string a,b;
	rep(m)
	{
		cin>>a>>b;
		var[b]=a;
	}
	cin>>k;
	while(k--)
	{
		cin>>a;
		while(a[a.size()-1]!=')')
		{
			cin>>b;
			a+=b;
		}
		cout<<solve(a)<<endl;
	}
	return 0;
}