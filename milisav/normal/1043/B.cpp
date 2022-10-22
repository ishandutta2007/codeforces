#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[4000];
vector<int> kp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int k=1;k<=n;k++) {
		bool p=true;
		for(int i=k+1;i<=n;i++) {
			if(a[i]-a[i-1]!=a[i-k]-a[i-1-k]) p=false;
		}
		if(p) kp.push_back(k);
	}
	printf("%d\n",kp.size());
	for(int i=0;i<kp.size();i++) printf("%d ",kp[i]);
	return 0;
}