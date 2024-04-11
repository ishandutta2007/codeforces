#include <iostream>
#include <algorithm>
#include <cmath>
//#include <queue>
//#include <set> 
//#include <string>
//#include <string.h>
//#include <stdio.h>
//#include <fstream>
//#include <stack>
//#define rep(N) for(int i=0;i<N;i++)
//#define repj(N) for(int j=0;j<N;j++)
//#define ll long long 
//#define pii pair<int,int> 
using namespace std;
void prime(int);
bool a[5010][5010];
char t[5010][5010];

bool b[5010];
void prime(int n)
{
	int i;
	for(i=2;i<=n;i++)
	{
		b[i]=true;
	}
	for(i=2;i<sqrt(n);i++)
	{
		for(int j=2;j<=n/i;j++)
		{
			b[i*j]=false;
		}
	}
} 

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
//	cout<<m<<endl;
//	system("pause");
	for(int i=0;i<n;i++)
	{
		scanf("%s",t[i]);
		for(int j=0;j<m;j++)
		{
//		if(j%100==0) cout<<j<<endl;
			a[i][j]=t[i][j]-48;
		}
	}
//	rep(n)
//	{
//		repj(m)
//		{
//			cout<<a[i][j]<<' ';
//		 } 
//		 cout<<endl;
//	}
	int mini=n*m;
	int ma=max(n,m),s,ss=0,sss=0;
//	cout<<ma<<endl;
	prime(ma);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=2;k<=ma;k++)
	{
		if(!b[k]) continue;
//		cout<<ma<<endl;
//		cout<<k<<endl;
//		system("pause");
		long long ik=(n/k)*k,jk=(m/k)*k,kk=k*k;
//		cout<<ik<<" "<<jk<<" "<<kk<<endl;
		for(int i=0;i<=ik;i+=k)
		{
			for(int j=0;j<=jk;j+=k)
			{
//				cout<<i<<' '<<j<<endl;
				s=0;
				for(int l=0;l<k;l++)
				{
					for(int b=0;b<k;b++)
					{
						s+=a[l+i][b+j];
					}
				}
//				if(k==2) cout<<s<<endl;
				if(kk-s>s) ss+=s;else ss+=kk-s;
			}
		}
//		cout<<ss<<"  "<<mini<<endl;
		if(mini>ss) mini=ss;
//		cout<<k<<"  "<<ss<<endl;
		ss=0;
	}
	cout<<mini<<endl;
	return 0;
}