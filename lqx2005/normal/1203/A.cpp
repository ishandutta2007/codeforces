#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include<climits>
typedef long long ll;
using namespace std;
const int N=10000;
int n,q;
int p[N+5];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&p[i]);
		int start;
		for(int i=0;i<n;i++) if(p[i]==1) start=i;
		vector<int> v;
		v.push_back(1);
		start=(start+1)%n;
		while(p[start]!=1)
		{
			v.push_back(p[start]);
			start=(start+1)%n;
		} 
		bool flag=0;
		for(int i=1;i<v.size();i++) if(v[i-1]+1!=v[i]) flag=1;
		bool flag2=0;
		for(int i=2;i<v.size();i++) if(v[i-1]!=v[i]+1) flag2=1;
		if(flag&&flag2) printf("NO\n");
		else printf("YES\n"); 
	}
	
	return 0;
}