#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		long long x=1ll*a*d,y=1ll*b*c;
		if(x==y)
			puts("0");
		else if(x==0||y==0||x%y==0||y%x==0)
			puts("1");
		else puts("2");
	}
	return 0;
}