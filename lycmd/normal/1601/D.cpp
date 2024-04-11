#include<bits/stdc++.h>
#define node pair<int,int>
#define a first
#define s second 
using namespace std;
int const N=500010;
int n,d,cnt;
node p[N];
int cmp(node x,node y){
	return max(x.a,x.s)<max(y.a,y.s)||max(x.a,x.s)==max(y.a,y.s)&&x.a<y.a;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].s;
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(p[i].a>=d)
		    cnt++,d=max(d,p[i].s);
	cout<<cnt<<"\n";
}