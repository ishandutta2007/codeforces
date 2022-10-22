#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int n,t_case;
char a[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",a+1);
		n=strlen(a+1)+1;
		int pos=0;
		for(ri i=1;i<n;++i)
			if(a[n-i]!='a'){
				pos=i;
				break;
			}
		if(pos){
			puts("YES");
			for(ri i=1;i<pos;++i)putchar(a[i]);
			putchar('a');
			for(ri i=pos;i<n;++i)putchar(a[i]);
			putchar(10);
		}
		else puts("NO");
	}
	return 0;
}