#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a,b,c,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&a,&b,&c);
		putchar(49);
		for(ri i=1;i<a;++i)putchar(48);
		putchar(32);
		while(b>=c)putchar(49),--b;
		for(ri i=1;i<c;++i)putchar(48);
		putchar(10);
	}
	return 0;
}