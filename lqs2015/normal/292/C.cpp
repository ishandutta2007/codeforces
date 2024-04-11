#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
vector<string> ans;
char tmp[99];
char s[10],t[99];
int n,in[10],k;
int u[10];
int a[4];
void point(int i,int j,int len)
{
	if (i==len && j==4)
	{
		sprintf(tmp,"%d.%d.%d.%d",a[0],a[1],a[2],a[3]);
		ans.push_back(tmp); 
	}
	if (i==len || j==4) return;
	if (i+(4-j)>len) return;
	if (i+3*(4-j)<len) return;
	if (i+1<=len) 
	{
		a[j]=(int)t[i];
		point(i+1,j+1,len);
	}
	if (i+2<=len && t[i]!=0)
	{
		a[j]=t[i]*10+t[i+1];
		point(i+2,j+1,len);
	}
	if (i+3<=len && t[i]!=0)
	{
		a[j]=t[i]*100+t[i+1]*10+t[i+2];
		if (a[j]<256)
		{
			point(i+3,j+1,len);
		}
	}
}
void add(int len)
{
	point(0,0,len);
}
void go(int i)
{
	bool good=1;
	for (int j=0;j<10;j++)
	{
		if (in[j] && !u[j]) good=0;
	}
	if (i && good)
	{
		memcpy(t,s,i);
		memcpy(t+i,s,i);
		reverse(t+i,t+2*i);
		add(2*i);
		memcpy(t+i,s,i-1);
		reverse(t+i,t+2*i-1);
		add(2*i-1);
	}
	if (i==6) return;
	for (int j=0;j<10;j++)
	{
		if (in[j])
		{
			s[i]=j;
			u[j]++;
			go(i+1);
			u[j]--;
		}
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		in[k]=1;
	}
	go(0);
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}