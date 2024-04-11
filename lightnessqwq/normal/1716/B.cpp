#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			a[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d%c",a[j],j==n? '\n':' ');
			swap(a[i],a[i+1]);
		}
	}
	return 0;
}