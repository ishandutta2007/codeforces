#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,m,cnt,a[N];
pair<int,int>b[N];
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i].first;
	for(int i=1;i<=m;i++)
		cin>>b[i].second;
	sort(b+1,b+1+m);
	for(int i=1,j=n;j;){
		while(i<=m&&b[i].first<=a[j])
			q.push(b[i++].second);
		int pre=a[j],cur=0;
		while(j&&a[j]<=pre)
			cur+=a[j--];
		while(!q.empty()){
			int x=q.top();q.pop();
			if(x<=cur)
				cur-=x,cnt++;
			else{
				q.push(x-cur);
				break;
			}
		}
	}
	cout<<cnt<<"\n";
}