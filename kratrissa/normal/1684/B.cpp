#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,a,b,c;char s[N];
void solve(){
	a=read(),b=read(),c=read();
	printf("%d %d %d\n",(c/b+1)*b+a,b,c);
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}