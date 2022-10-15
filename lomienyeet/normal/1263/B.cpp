#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin>>N;
	string s[N];
	set<string> se;
	for(int i=0;i<N;i++){cin>>s[i];se.insert(s[i]);}
	map<string,int> mp;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(mp[s[i]]>0){
			cnt++;
			int temp=0;
			while(se.find(s[i])!=se.end()){
				s[i][3]=temp+'0';
				temp++;
			}
		}
		mp[s[i]]++;
		se.insert(s[i]);
	}
	cout<<cnt<<"\n";
	for(int i=0;i<N;i++)cout<<s[i]<<"\n";
}
int main(){
	int T=1;
	cin>>T;
	while(T--)solve();
}