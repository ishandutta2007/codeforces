#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=2e5+5;
int n;
int ans=0;
inline int calc(int x){
	return 2*n*x;
}
int a[N];
signed main(){
	cin>>n;
	int l=0,r=n*n+n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(calc(mid)>n*n*(2*n+1)) r=mid-1;
		else if(calc(mid)<n*n*(2*n+1)-2*n) l=mid+1;
		else {
			ans=mid;
			break;
		}
	}
	if(!ans||calc(ans)!=n*n*(2*n+1)-n) {
		puts("NO");return 0;
	}
	int s=0,s1=ans,s2=ans+1;
	for(int i=1;i<=n-1;i+=2) a[i]=i,s+=a[i];
	for(int i=2;i<=n-1;i+=2) a[i]=2*n-i+2,s+=a[i];
	a[n]=s1-s;s+=a[n];
	for(int i=n+1;i<=2*n;i++){
		s-=a[i-n];
		a[i]=(((i-n)&1)?s2:s1)-s;
		s+=a[i];
	}
	puts("YES");
	for(int i=1;i<=2*n;i++) printf("%I64d ",a[i]);
	return 0;
}