#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int ind = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==m)ind=i;
	}
	
	map<int,int> cnt;
	int now = 0;
	cnt[now]++;
	for(int i=0;i<ind;i++){
		if(a[i]<m)now--;
		else now++;
		cnt[now]++;
	}
	
	long long ans = 0;
	for(int i=ind;i<n;i++){
		if(a[i]<m)now--;
		else if(a[i]>m)now++;
		ans=(long long)ans+cnt[now];
		ans=(long long)ans+cnt[now-1];
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}