#include<bits/stdc++.h>
using namespace std;
string s="abc";
int k,n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		while(n--)putchar(s[n%3]);
		puts("");
	}
	return 0;
}