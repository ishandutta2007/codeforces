#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+9;

int T,n;
char s[N];

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s+1);
		int cnt0=0, cnt1=0;
		rep(i,1,n-1) {
			if(s[i]=='0'&&s[i+1]=='0') cnt0++;
			else if(s[i]=='1'&&s[i+1]=='1') cnt1++;
		}
		printf("%d\n",max(cnt0,cnt1));
	}
	return 0;
}