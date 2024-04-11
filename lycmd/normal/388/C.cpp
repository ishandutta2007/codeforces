#include<bits/stdc++.h>
using namespace std;
int n,ans[2];
priority_queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int k;n--;){
		cin>>k; 
		for(int i=1,x;i<=k;i++){
			cin>>x;
			if(k&1&&i==(k+1)/2)q.push(x);
			else ans[i*2>k]+=x;
		}
	} 
	for(int i=0;!q.empty();i^=1)
		ans[i]+=q.top(),q.pop();
	cout<<ans[0]<<" "<<ans[1]<<"\n";
}