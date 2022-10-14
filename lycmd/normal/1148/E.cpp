#include<bits/stdc++.h>
#define int long long
#define val first
#define id second
using namespace std;
int const N=333333;
int n,sum,tot,df[N];
pair<int,int>a[N],b[N];
stack<int>s;
struct node{int l,r,d;}e[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].val,a[i].id=i;
	for(int i=1;i<=n;i++)
		cin>>b[i].val,b[i].id=i;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		sum+=df[i]=b[i].val-a[i].val;
		if(sum<0){cout<<"NO\n";return 0;}
	}
	if(sum){cout<<"NO\n";return 0;}
	for(int i=1;i<=n;i++)
		if(df[i]>0)s.push(i);
		else if(df[i]){
			while(!s.empty()){
				int t=s.top(),d=min(a[i].val-b[i].val,b[t].val-a[t].val);
				a[i].val-=d,a[t].val+=d;
				e[++tot]={a[t].id,a[i].id,d};
				if(a[i].val==b[i].val)break;
				s.pop();
			}
		}
	cout<<"YES\n"<<tot<<"\n";
	for(int i=1;i<=tot;i++)
		cout<<e[i].l<<" "<<e[i].r<<" "<<e[i].d<<"\n";
}