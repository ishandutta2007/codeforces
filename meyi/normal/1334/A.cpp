#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a,b,la,lb,n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		la=lb=0;
		bool flag=false;
		while(n--){
			scanf("%d%d",&a,&b);
			if(a<lb||b<lb||a-la<b-lb)flag=true;
			la=a,lb=b;
		}
		puts(flag?"NO":"YES");
	}
	return 0;
}