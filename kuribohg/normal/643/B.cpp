#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> v;
int n,m,a,b,c,d;
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
	if(n==4||m==n-1||m==n) {puts("-1");return 0;}
	v.push_back(a),v.push_back(c);
	for(int i=1;i<=n;i++)
		if(i!=a&&i!=b&&i!=c&&i!=d) v.push_back(i);
	v.push_back(d),v.push_back(b);
	for(int i=0;i<n;i++) printf("%d ",v[i]);
	puts("");
	printf("%d %d ",v[1],v[0]);
	for(int i=2;i<n-2;i++) printf("%d ",v[i]);
	printf("%d %d \n",v[n-1],v[n-2]);
	return 0;
}