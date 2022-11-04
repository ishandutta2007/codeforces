#include<bits/stdc++.h>
using namespace std;
const int N=509;
int T,a[N],b[N];
int main(){
	cin>>T;
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		int ans=1;
		for(int i=1;i<=n;i++) if(a[i]<a[i-1]) ans=0;
		if(ans){puts("Yes");continue;}
		int c[2]={0,0};
		for(int i=1;i<=n;i++) c[b[i]]++;
		if(c[0]&&c[1]) puts("Yes");
		else puts("No");
	}
	return 0;
}