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
#include <chrono>
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
ll a[100005];
map <ll,int> m;
vector <pair<ll,ll> >vec;
vector <int> rubbish;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(int i=0;i<n-1;i++)
	{
		m[a[i+1]-a[i]]++;
//		vec.push_back(a[i+1]-a[i]);
	}
//	for(int i=0;i<n;i++)
//	{
//		m[1e18-a[i]]++;
//	}
	vec.push_back(mp(0,0));
	rubbish.push_back(n);
	int spam=0;
	ll time=0;
	for(auto x:m)
	{
//		cout<<x.first<<' '<<x.second<<endl;
		vec.push_back(mp(x.first,vec[vec.size()-1].second+1LL*(x.first-time)*(n-spam)));
		rubbish.push_back(n-spam-x.second);
		spam+=x.second;
		time=x.first;
	}
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i].first<<'-'<<vec[i].second<<'-'<<rubbish[i]<<endl;
//	}
	int q;
	cin>>q;
	ll l,r;
	while(q--)
	{
		scanf("%I64d%I64d",&l,&r);
		ll len=r-l+1;
		int pos=upper_bound(all(vec),mp(len,0LL))-vec.begin();
		pos--;
		ll time=vec[pos].first;
		ll res=vec[pos].second;
		res+=1LL*(len-time)*rubbish[pos];
		printf("%I64d\n",res);
//		pair<ll,ll> t=*m.lower_bound(len);
//		cout<<t.first<<' '<<t.second<<endl;
	}
	return 0;
}