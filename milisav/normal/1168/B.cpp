#include<bits/stdc++.h>
using namespace std;
int n;
char s[600000];
bool check(int a,int m) {
	for(int i=0;i<m;i++) {
		for(int j=1;i+2*j<m;j++) {
			if((a&(1<<i)) && (a&(1<<(i+j)))  && (a&(1<<(i+2*j)))) return true;
			if(!(a&(1<<i)) && !(a&(1<<(i+j)))  && !(a&(1<<(i+2*j)))) return true;
		}
	}
	return false;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	long long ans=0;
	for(int i=0;i<n;i++) {
		int t=0;
		int k=0;
		for(int j=i;j>=i-7 && j>=0;j--) {
			if(s[j]=='1') t+=(1<<k);
			k++;
			//printf("%d %d - %d %d\n",i,j,t,k);
			if(check(t,k)) {
				ans++;
			}
		}
		if(i>=7) ans+=(i-7);
	}
	printf("%lld",ans);
	return 0;
}