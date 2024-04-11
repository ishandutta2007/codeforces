#include<cstdio>
#include<algorithm>
using namespace std;

#define ran 202202

int n, s;
int a[ran];

int main() {
	scanf("%d%d", &n, &s);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n);
	
	int mid = n/2;
	long long ans = 0LL;
	if (a[mid]>s) {
		for(int i=mid;i>=0 && a[i]>s; i--)
			ans += a[i]-s;
	} else {
		for(int i=mid;i<n && a[i]<s; i++)
			ans += s-a[i];
	}
	printf("%I64d\n", ans);
	
	return 0;
}