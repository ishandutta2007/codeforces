#include<bits/stdc++.h>
using namespace std;
int p[50];
int main()
{
	int q;
	scanf("%d",&q);
	int a;
	int b;
	int l;
	while(q--) {
		scanf("%d",&a);
		b=1;
		l=0;
		while(b<=a){
			b=(b<<1);
			l++;
		}
		if(b!=a+1) b=b-a-1;
		else {
			if(p[l]==0) {
				p[l]=1;
				for(int i=2;i*i<=a;i++) {
					if(a%i==0) {
						p[l]=a/i;
						break;
					}
				}
			}
			b=p[l];
		}
		printf("%d\n",__gcd(a^b,a&b));
	}
	return 0;
}