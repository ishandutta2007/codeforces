#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,k,w,ans,cur,s,flg;
struct node{
	int v,a,b;
	int operator<(const node&rhs)const{
		return b-a>rhs.b-rhs.a;
	}
};
node p[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i].v>>p[i].a>>p[i].b,w+=p[i].v,ans+=p[i].v*p[i].a;
	p[++n]={(k-w%k)%k,0,0},sort(p+1,p+1+n);
	for(int i=1;i<=n;i++){
		int c=p[i].b-p[i].a;
		if(s+p[i].v>=k){
			ans+=max(0ll,cur+(k-s)*c);
			cur=0,p[i].v-=k-s;
			ans+=max(0ll,p[i].v/k*k*c);
			s=p[i].v%k,cur=s*c;
		}else
			s+=p[i].v,cur+=p[i].v*c;
	}
	cout<<ans<<"\n";
}