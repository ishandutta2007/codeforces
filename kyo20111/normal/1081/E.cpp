#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,L,LL;
ll x[100100],o[200200];
int main(){
	for(int i=1;i<=200001;i++) o[i] = 2*i-1 + o[i-1];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",x+i*2);

	for(int i=1;i<=n;i++){
		if(i%2){
			while(++L <= 200000){
				int l = L, r = 200000;
				while(l<=r){
					int mid = (l+r)>>1;
					if(o[mid]-o[L-1] < x[i+1]) l = mid+1;
					else if(o[mid]-o[L-1] > x[i+1]) r = mid-1;
					else{
						l = mid;
						break;
					}
				}
				if(o[l] - o[L-1] == x[i+1]){
					if(L-1 == LL) continue;
					x[i] = o[L-1] - o[LL];
					L = LL = l;
					break;
				}
			}
			if(L > 200000) return !printf("No");
		}
		x[i] += x[i-1];
	}

	printf("Yes\n");
	for(int i=1;i<=n;i++) printf("%lld ",x[i]-x[i-1]);
}