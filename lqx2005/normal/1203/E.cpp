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
const int N=150000;
int n;
int a[N+5]; 
bool vis[N+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int tot=0;
	for(int i=1;i<=n;i++) 
	{
		if((!vis[a[i]-1])&&a[i]-1>0) vis[a[i]-1]=1,tot++;
		else if(!vis[a[i]]) vis[a[i]]=1,tot++;
		else if(!vis[a[i]+1]) vis[a[i]+1]=1,tot++;
	}
	printf("%d\n",tot);
	return 0;
}