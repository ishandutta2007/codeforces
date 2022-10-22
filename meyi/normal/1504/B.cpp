#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int n,s[maxn],t_case;
char a[maxn],b[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%s",&n,a+1,b+1);
		for(ri i=1;i<=n;++i)s[i]=s[i-1]+(a[i]=='1');
		bool flag1=false,flag2=false;
		for(ri i=n;i;--i){
			a[i]^=48,b[i]^=48;
			if((a[i]^flag1)!=b[i]){
				if(s[i]*2!=i){
					flag2=true;
					break;
				}
				flag1^=1;
			}
		}
		puts(flag2?"NO":"YES");
	}
	return 0;
}