#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d%d",&n,&m);
	while(n>0)
		for(ri i=0;i<m&&n>0;++i){
			if(n-->0)putchar('a'+i);
			for(ri j=i+1;j<m&&n>0;++j){
				if(n-->0)putchar('a'+i);
				if(n-->0)putchar('a'+j);
			}
		}
	return 0;
}