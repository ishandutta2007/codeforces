#include<bits/stdc++.h>
using namespace std;
long long int n;
int a[200000];
long long l[200000];
bool p[200000];
long long int t;
long long int s=0;
int main() {
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	t=0;
	for(int i=0;i<n;i++) {
		s-=l[a[i]];
		l[a[i]]=t;
		s+=t;
		if(!p[a[i]]) {
			p[a[i]]=true;
			t++;
		}
	}
	printf("%lld",s);
	return 0;
}