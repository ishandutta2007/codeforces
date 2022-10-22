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
char c[200005];
int cp[200005];
stack <int> stk;
bool used[200005];
vector <int> order;
vector <int> res;
set <pair<int,int> > b;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
//	int now=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='(')
		{
			stk.push(i);
		}
		else
		{
			int x=stk.top();
			stk.pop();
			cp[i]=x;
			cp[x]=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(used[i]) continue;
		order.push_back(i);
		used[cp[i]]=true;
		used[i]=true;
	}
	reverse(order.begin(),order.end());
	for(int i=0;i<k/2;i++)
	{
		res.push_back(order[i]);
		b.insert(mp(order[i],0));
		b.insert(mp(cp[order[i]],1));
	}
	for(set <pii> :: iterator it=b.begin();it!=b.end();it++)
	{
		if(it->second==1) printf(")");else printf("(");
	}
//	sort(res.begin(),res.end());
//	for(int i=0;i<res.size();i++)
//	{
//		cout<<res[i]<<' ';
//	}
	return 0;
}