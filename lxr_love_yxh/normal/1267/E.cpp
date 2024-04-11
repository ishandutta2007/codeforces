#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

int n,m,p,ans;
int a[105][105];
int b[105];
pair<int,int> c[105];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&a[j][i]);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++) b[j]=a[i][j]-a[n][j];
		sort(b+1,b+1+m);
		reverse(b+1,b+1+m);
//		for(int j)
		int j,tot=0;
		for(j=1;j<=m;j++){
			tot+=b[j];
			if(tot<0) break;
		}
		j--;
		ans=max(ans,j);
		if(ans==j) p=i;
	}
	printf("%d\n",m-ans);
	for(int i=1;i<=m;i++) c[i]=make_pair(a[p][i]-a[n][i],i);
	sort(c+1,c+1+m);
	reverse(c+1,c+1+m);
	int i,tot=0;
	for(i=1;i<=m;i++){
		tot+=c[i].first;
		if(tot<0) break;
	}
	for(;i<=m;i++) printf("%d ",c[i].second); puts("");
	return 0;
}