#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;
int n,i,ans,x[1010],y[1010],f[1010];
int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y) {
	if (find(x)!=find(y)) f[f[x]]=f[y],ans--;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=0;i<n;i++) f[i]=i;ans=n-1;
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (x[i]==x[j] || y[i]==y[j]) merge(i,j);
	printf("%d\n",ans);
}