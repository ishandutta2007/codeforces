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
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
const int m1=1e9+7;
const int m2=19260817;
char c[1000005];
int n;
ll e1[1000005];
ll e2[1000005];
ll sum1[1000005];
ll sum2[1000005];

int calc1(int l,int r)
{
	ll res=sum1[r]-(l?sum1[l-1]:0)*e1[r-l+1];
	res%=m1;
	res+=m1;
	res%=m1;
	return res;
}

int calc2(int l,int r)
{
	ll res=sum2[r]-(l?sum2[l-1]:0)*e2[r-l+1];
	res%=m2;
	res+=m2;
	res%=m2;
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	n=strlen(c);
	if(n==3 && c[0]=='0' && c[1]=='0' && c[2]=='0')
	{
		cout<<"0+0=0"<<endl;
		return 0;
	}
	e1[0]=e2[0]=1;
	sum1[0]=sum2[0]=c[0]-'0';
	for(int i=1;i<=1000000;i++)
	{
		e1[i]=e1[i-1]*10;
		e1[i]%=m1;
		e2[i]=e2[i-1]*10;
		e2[i]%=m2;
		sum1[i]=sum1[i-1]*10+c[i]-'0';
		sum1[i]%=m1;
		sum2[i]=sum2[i-1]*10+c[i]-'0';
		sum2[i]%=m2;
	}
//	cout<<calc2(0,8)<<' '<<calc2(9,17)<<' '<<calc2(18,26)<<endl;
	int lenl,lenr,lena;
	int k1=-1,k2=-1;
	vector <int> vec;
	for(int l=0;l<n-1;l++)
	{
		if(l!=0 && c[0]=='0') break;
		lenl=l+1;
		vec.clear();
		for(int r=(n-lenl)/2+lenl-3;r<(n-lenl)/2+lenl+3;r++)
		{
			vec.push_back(r);
		}
		for(int r=n-lenl-3;r<(n-lenl+3);r++)
		{
			vec.push_back(r);
		}
//		cout<<l<<':';
//		for(int i=0;i<vec.size();i++)
//		{
//			cout<<vec[i]<<' ';
//		}
//		cout<<endl;
		for(int i=0;i<vec.size();i++)
		{
			int r=vec[i];
//			cout<<vec[i]<<' ';
//			if(l==0 && r==3) cout<<"FUCK";
			if(r<=l || r>=n-1) continue;
			if(r-l>1 && c[l+1]=='0') continue;
			if(c[r+1]=='0') continue;
			if((calc1(0,l)+calc1(l+1,r))%m1==calc1(r+1,n-1) && (calc2(0,l)+calc2(l+1,r))%m2==calc2(r+1,n-1))
			{
				k1=l;
				k2=r;
				break;
			}
		}
		if(k1!=-1) break;
	}
	for(int i=0;i<n;i++)
	{
		putchar(c[i]);
		if(i==k1) putchar('+');
		if(i==k2) putchar('=');
	}
	return 0;
}