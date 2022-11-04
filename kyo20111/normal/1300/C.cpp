#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[100100], cnt[30];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	int mx = 0;
	for(int i=1;i<=n;i++) mx = max(mx, a[i]);
	int bit = 1, bc = 0;
	while(bit < mx) bit *= 2, bc++;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=bc;j++) if(a[i] & (1<<j)) cnt[j]++;
	}

	mx = 0;
	int mxc = 1;
	for(int i=1;i<=n;i++){
		int re = 0;
		for(int j=0;j<=bc;j++) if(cnt[j] == 1 && (a[i] & (1<<j))) re += (1<<j);
		if(re > mx){
			mx = re;
			mxc = i;
		}
	}

	printf("%d ",a[mxc]);
	for(int i=1;i<=n;i++) if(i != mxc) printf("%d ",a[i]);
}