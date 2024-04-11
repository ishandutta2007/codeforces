#include <bits/stdc++.h>
using namespace std;

int get_beki(int x){
	int a = 1;
	while(true){
		if(a>x)return a-x;
		a*=2;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> mp;
	map<int,bool> m_f;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
		m_f[a[i]]=false;
	}
	sort(a.begin(),a.end(),greater<int>());
	
	int ans = 0;
	for(int i=0;i<n;i++){
		int x = get_beki(a[i]);
		mp[a[i]]--;
		if(mp[x]>0){
			m_f[x]=true;
			m_f[a[i]]=true;
		}
		mp[a[i]]++;
		if(m_f[a[i]]==false)ans++;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}