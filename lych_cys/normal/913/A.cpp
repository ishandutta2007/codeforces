#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if (n<=30){
		printf("%d\n",m%(1<<n));	
	} else printf("%d\n",m);
	return 0;
}