#include<bits/stdc++.h>
using namespace std;
int a[200001],now=1;
vector<int>s;
void wk(int x){s.push_back(x);while(!s.empty()&&s.back()==now)s.pop_back(),now++;}
int main(){
	int n,k;
	cin>>n>>k;
	s.push_back(n+1);
	for(int x=1;x<=k;x++)
	cin>>a[x],wk(a[x]);
	for(int x=k+1;x<=n;x++)
	a[x]=s.back()-1,wk(a[x]);
	if(!s.empty())return 0*puts("-1");
	for(int x=1;x<=n;x++)cout<<a[x]<<' ';
}