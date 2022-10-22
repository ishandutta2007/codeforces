#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[1010];
pair<int,int> b[1010];
pair<int,int> o[1010];
bool test(int x,int y) {
	for(int i=0;i<n;i++) {
		b[i].first=x-o[i].first;
		b[i].second=y-o[i].second;
	}
	sort(b,b+n);
	for(int i=0;i<n;i++) {
		if(b[i].first!=a[i].first || b[i].second!=a[i].second) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++) {
		scanf("%d %d",&x,&y);
		o[i].first=x;
		o[i].second=y;
	}
	for(int i=0;i<n;i++) {
		scanf("%d %d",&x,&y);
		a[i].first=x;
		a[i].second=y;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) {
		if(test(o[0].first+a[i].first,o[0].second+a[i].second)) {
			printf("%d %d",o[0].first+a[i].first,o[0].second+a[i].second);
			return 0;
		}
	}
	return 0;
}