#include <iostream>
#include <fstream>
#include <map>

using namespace std;


int gcd(int a,int b)
{
	while (b!=0)
	{
		int q=a;
		a=b;
		b=q%b;
	}
	return a;
}

const int MAX_N=5100;

int n,m;

int ggg[MAX_N];
int arr[MAX_N];
int b[MAX_N];

map<int,int> save;


int f(int a)
{
	if (save.find(a)!=save.end())
		return save[a];
	int a2 = a;
	int res=0;
	int i=2;
	int now=0;
	while (i*i<=a)
	{
		while (now<m-1 && b[now]<i)
			++now;
		if (a%i==0)
		{
			if (b[now]==i)
				--res;
			else
				++res;
			a/=i;
		}
		else
			++i;
	}
	if (a==1)
	{
		save[a2]=res;
		return res;
	}
	else
	{
		while (now<m-1 && b[now]<a)
			++now;
		if (b[now]==a)
			--res;
		else
			++res;
		save[a2]=res;
		return res;
	}
}




int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=0;i<n;++i)
		cin>>arr[i];
	
	for (int i=0;i<m;++i)
		cin>>b[i];
	
	ggg[0]=arr[0];
	for (int i=1;i<n;++i)
		ggg[i]=gcd(ggg[i-1],arr[i]);
	
	int k=1;
	
	
	for (int i=n-1;i>=0;--i)
	{
		int y=ggg[i]/k;
		int x=f(y);
		if (x<0)
			k*=y;
		arr[i]/=k;
	}
	int ans=0;
	for (int i=0;i<n;++i)
		ans+=f(arr[i]);
	cout<<ans;
}