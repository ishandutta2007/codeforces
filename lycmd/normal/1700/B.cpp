#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
string s;
string sub(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(auto&i:a)i-=48;
	for(auto&i:b)i-=48;
	string res;
	int m=a.size();
	res.resize(m);
	while(b.size()<m)b+=(char)0;
	for(int i=0;i<m;i++){
		res[i]=a[i]-b[i];
		if(res[i]<0)res[i]+=10,a[i+1]--;
	}
	while(!res.back())res.pop_back();
	reverse(res.begin(),res.end());
	for(auto&i:res)i+=48;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>s;
		string t=sub(string(n+1,49),s);
		cout<<(t.size()>n?sub(string(n,57),s):t)<<"\n";
	}
}