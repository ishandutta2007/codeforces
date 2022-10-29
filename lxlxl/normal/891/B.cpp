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
struct node{int x,i;}a[maxn];
inline bool cmp(const node x,const node y){return x.x<y.x;}

int b[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].i=i;
	sort(a+1,a+n+1,cmp); a[n+1].x=a[1].x;
	
	for(int i=1;i<=n;i++) b[a[i].i]=a[i+1].x;
	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	
	return 0;
}