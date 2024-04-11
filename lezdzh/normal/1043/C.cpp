#include<cstdio>
#include<cstring>
using namespace std;

char s[1011];
int w[1001];
void cc(int n){
	if(!n)return;
	int mn=2e9;
	for(int i=1;i<=n;i++)
		if(s[i]<mn)mn=s[i];
	int r=n,l;
	while(s[r]!=mn)r--;
	for(l=r;s[l-1]==mn;l--);
	cc(l-1);
	w[r]^=1;
	w[n]^=1;
}
int main(){
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	cc(n);
	w[n]^=1;
	for(int i=1;i<=n;i++)
		printf("%d%c",w[i],i==n?'\n':' ');
}