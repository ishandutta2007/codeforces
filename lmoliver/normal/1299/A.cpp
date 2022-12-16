#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
int a[N];
int pre[N],suf[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]|a[i];
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]|a[i];
	}
	pair<int,int> ans{-1,1};
	for(int i=1;i<=n;i++){
		ans=max(ans,make_pair(a[i]&~(pre[i-1]|suf[i+1]),i));
	}
	cout<<a[ans.second];
	for(int i=1;i<=n;i++){
		if(i!=ans.second){
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
	return 0;
}