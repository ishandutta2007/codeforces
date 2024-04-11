#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333;
int n,m,k,g,l,x,y,a[N],b[N],p[N];
vector<int>c;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int a,int b,int&x,int&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y,y=t-a/b*x;
}
int check(int x){
	int res=x/l*c.size();
	for(int i:c)res+=i&&i<=x%l;
	return(x-res)>=k;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k,g=gcd(n,m),l=n/g*m,exgcd(n/g,m/g,x,y);
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=i;
	for(int i=1;i<=m;i++)
		if(cin>>b[i],p[b[i]]&&(i-p[b[i]])%g==0)
			c.push_back((n*x*(i-p[b[i]])/g%l+p[b[i]]+l)%l);
	int l=0,r=1e18;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}
//?