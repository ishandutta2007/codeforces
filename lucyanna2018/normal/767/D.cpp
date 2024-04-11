#include<bits/stdc++.h>
using namespace std;
#define ran 1111111
int n,m,k;
int a[ran];
pair<int,int> b[ran];
int c[ran * 2],lc;
bool ok(int x){
	lc = 0;
	for(int i = 0, j = m - x; i < n || j < m; ){
		if(i<n && (j==m || a[i] < b[j].first)){
			c[lc++] = a[i];
			i++;
		}
		else{
			c[lc++] = b[j].first;
			j++;
		}
	}
	for(int i = 0, j = 0; i < lc; i += k, j++){
		for(int i2 = i; i2 < lc && i2 < i+k; i2++)
			if(c[i2] < j)
				return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0; i<m; i++){
		scanf("%d",&b[i].first);
		b[i].second = i+1;
	}
	sort(b,b+m);
//	for(int i=0; i<m; i++)
//		printf("%d ",b[i].second);
//	puts("");
	int lo = -1, hi = m;
	while(lo!=hi){
		int mi = (lo + hi + 1)/2;
		if(ok(mi))
			lo = mi;
		else
			hi = mi-1;
	}
	if(lo == -1)puts("-1");else{
		printf("%d\n",lo);
		for(int i=0; i<lo; i++){
			printf("%d%c",b[m-1-i].second,i<lo-1?' ':'\n');
		}
	}
	return 0;
}