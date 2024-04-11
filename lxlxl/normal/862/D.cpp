#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 1100;

int n;
char str[maxn];
int kk,k1,k2;

int pos0,pos1,now;

bool judge(int l,int r)
{
	for(int i=0;i<n;i++) str[i]='0';
	for(int i=l;i<=r;i++) str[i]=now==0?'0':'1';
	if(now==0) k1=kk;
	else
	{
	cout<<'?'<<' '<<str; cout<<endl;
	
	cin>>k1;
	}
	for(int i=l;i<=r;i++) str[i]=now==0?'1':'0';
	if(now==1) k2=kk;
	else
	{
	cout<<'?'<<' '<<str; cout<<endl;
	
	cin>>k2;
	}
	if(k1+(r-l+1)==k2) return false;
	else return true;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) str[i]='0';
	cout<<'?'<<' '<<str; cout<<endl;
	cin>>k1; kk=k1;
	str[0]='1';
	cout<<'?'<<' '<<str; cout<<endl;
	cin>>k2;
	pos0=0;
	if(k1>k2) now=1;
	else now=0;
	
	int l=1,r=n-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(judge(l,mid)) r=mid-1;
		else l=mid+1;
	}
	pos1=r+1;
	if(now==1) swap(pos0,pos1);
	cout<<'!'<<' '<<pos0+1<<' '<<pos1+1<<endl;
	
	return 0;
}