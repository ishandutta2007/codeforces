#include<bits/stdc++.h>
using namespace std;
int const N=233,M=10000010;
int n,ans[N],vis[M];
struct node{
	int l,r,id;
	int operator<(const node&rhs)const{
		return r<rhs.r||(r==rhs.r&&l<rhs.l);
	}
};
node a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].r,a[i].id=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=a[i].l;j<=a[i].r;j++)
			if(!vis[j]){
				ans[a[i].id]=j,vis[j]=1;
				break;
			}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}