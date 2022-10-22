#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b,k1,k2,m,n,t_case,w;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
		if(k1<k2)swap(k1,k2);
		int wlim=k2+(k1-k2)/2,blim=n-k1+((n-k2)-(n-k1))/2;
		if(w>wlim||b>blim){
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}