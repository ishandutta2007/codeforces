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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
pii a[505];
vector <pair<int,int> > res;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a,a+n);
	int sum2=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].first>=2) sum2++;
	}
	if(sum2==n)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		for(int i=0;i<n-1;i++)
		{
			cout<<i+1<<' '<<i+2<<endl;
		}
	}
	else if(sum2==n-1)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i].second+1<<' '<<a[i+1].second+1<<endl;
		}
	}
	else if(sum2==n-2)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		swap(a[1],a[n-1]);
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i].second+1<<' '<<a[i+1].second+1<<endl;
		}
	}
	else
	{
		int d=0;
		for(int i=n-sum2;i<n-1;i++)
		{
			res.push_back(mp(a[i].second+1,a[i+1].second+1));
			a[i].first--;
			a[i+1].first--;
			d++;
		}
//		cout<<a[n-1]<<endl;
		int last=n-1;
//		cout<<a[n-sum2].second+1<<endl;
		res.push_back(mp(a[0].second+1,a[n-sum2].second+1));
		a[n-sum2].first--;
		for(int i=1;i<n-sum2;i++)
		{
//			cout<<i<<endl;
			while(a[last].first==0)
			{
				last--;
				if(last<n-sum2) over("NO");
			}
			res.push_back(mp(a[i].second+1,a[last].second+1));
			a[last].first--;
		}
		cout<<"YES "<<d+2<<endl;
		cout<<res.size()<<endl;
		for(int i=0;i<res.size();i++)
		{
			cout<<res[i].first<<' '<<res[i].second<<endl;
		}
//		int sum=0;
//		for(int i=0;i<n;i++)
//		{
//			sum+=a[i];
//		}
//		if(sum>=(n-1)*2)
//		{
//			
//		}
//		else
//		{
//			cout<<"NO\n";
//		}
	}
	return 0;
}