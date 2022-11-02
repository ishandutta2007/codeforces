#include <bits/stdc++.h>

int n,arr[100005];

int main() {int cnt=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
	} for (int i=2;i<=n;++i) {
		if (arr[i]==1) {
			if (arr[i-1]==2) cnt+=3;
			else 
				cnt+=4; 
		} if (arr[i]==2) {
			if (arr[i-1]==1) {
				cnt+=3;
				if (i>2&&arr[i-2]==3) cnt--;
			}
			else {printf("Infinite");return 0;}
		} if (arr[i]==3) {
			if (arr[i-1]==1) cnt+=4;
			else {printf("Infinite");return 0;}
		}
	}printf("Finite\n%d",cnt);
	return 0;
}