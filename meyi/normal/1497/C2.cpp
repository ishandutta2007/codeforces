#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int m,n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		while(m>3)printf("1 "),--m,--n;
		if(n&1)printf("1 %d %d\n",n/2,n/2);
		else{
			if(n%4==0)printf("%d %d %d\n",n/2,n/4,n/4);
			else printf("2 %d %d\n",n/2-1,n/2-1);
		}
	}
	return 0;
}