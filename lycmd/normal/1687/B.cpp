#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333;
int n,m,x,ans;
string s;
pair<int,int>e[N];
int ask(const string&s){
	return cout<<"? "<<s<<endl,cin>>x,x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,s=string(m,48);
	for(int i=0;i<m;i++)
		s[i]++,e[i]={ask(s),i},s[i]--;
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int x=e[i].second,w=e[i].first;
		s[x]++;
		if(ask(s)<ans+w)s[x]--;else ans+=w;
	}
	cout<<"! "<<ans<<endl;
}