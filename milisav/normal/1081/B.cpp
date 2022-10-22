#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[200000];
pair<int,int> b[200000];
int main() {
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&x);
		a[i]=make_pair(x,i);
	}
	sort(a,a+n);
	int d=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-a[i].first;j++) {
			if(i+j>=n || a[i+j].first!=a[i].first) {
				printf("Impossible");
				return 0;
			}
			b[i+j]=make_pair(a[i+j].second,d);
		}
		i+=(n-a[i].first-1);
		d++;
	}
	sort(b,b+n);
	printf("Possible\n");
	for(int i=0;i<n;i++) printf("%d ",b[i].second);
	return 0;
}