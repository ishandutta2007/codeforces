#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ri r=sqrt((n<<1)-1);
		printf("%d\n",((r+1)>>1)-1);
	}
	return 0;
}