#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,ans,a[N],b[N];
stack<int>s;
vector<int>v;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(!s.empty()&&a[s.top()]<=a[i]-i+s.top())
			s.pop();
		s.push(i);
	}
	for(;!s.empty();s.pop())
		v.push_back(s.top());
	reverse(v.begin(),v.end());
	for(int x:v)
		for(int i=x;i>=x-a[x];i--)
			if(!b[i])b[i]=a[x]-x+i;
			else break;
	for(int i=1;i<=n;i++)
		b[i]=max(b[i],b[i-1]),ans+=b[i]-a[i];
	cout<<ans<<"\n";
}