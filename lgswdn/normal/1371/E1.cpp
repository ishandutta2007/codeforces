#include<bits/stdc++.h>
using namespace std;
const int N=2009;

int a[N],big[2*N];
vector<int>v;

int main() {
	int n,p; scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),big[a[i]]++;
	sort(a+1,a+n+1);
	for(int x=1;x<=a[n]+n;x++) big[x]+=big[x-1];
	for(int x=1;x<=a[n];x++) {
		bool good=1; int y=x;
		for(int i=1;i<=n;i++) {
			int c=big[y]-(i-1);
			if(c%p==0) {good=0;break;}
			y++;
		}
		if(good) v.push_back(x);
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	return 0;
}