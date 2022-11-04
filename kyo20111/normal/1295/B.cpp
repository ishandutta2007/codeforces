#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, b[100100];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			int a; scanf("%01d",&a);
			b[i] = b[i-1] + (a ? -1 : 1);
		}
		int ans = (m == 0);
		if(b[n] == 0){
			int fl = 0;
			for(int i=1;i<=n && !fl;i++) if(b[i] == m) fl = 1;
			if(fl) printf("-1\n");
			else printf("0\n");
			continue;
		}

		if(m < 0){
			m = -m;
			for(int i=1;i<=n;i++) b[i] = -b[i];
		}

		for(int i=1;i<=n;i++){
			if((!((m - b[i] >= 0) ^ (b[n] >= 0)) && ((m - b[i]) % b[n] == 0)) || b[i] == m) ans++;
		}

		printf("%d\n",ans);
	}
}