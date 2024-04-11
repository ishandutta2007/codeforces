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
int n,k;
int a[100005];
map <ll,int> m;

ll check(ll x)
{
//	cout<<x<<':'<<'\n';
	m.clear();
	ll pre=0;
	ll res=0;
	for(int i=0;i<n;i++)
	{
		m[pre]++;
//		cout<<pre-x<<endl;
		pre+=a[i];
		res+=m[pre-x];
//		cout<<pre<<endl;
//		m[pre]++;
	}
//	cout<<x<<' '<<res<<endl;
	return res;
}

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	ll basic=1;
	ll res=0;
	bool f=false;
	while(basic<=1e14)
	{
		res+=check(basic);
		basic*=k;
		if(basic==1) break;
	}
	cout<<res<<endl;
	return 0;
}