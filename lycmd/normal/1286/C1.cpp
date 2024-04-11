#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,cnt[N],cur[N];
multiset<string>ms;
string s;
vector<string>ans;
int main(){
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;i++)
		cin>>s,sort(s.begin(),s.end()),ms.insert(s);
	if(n==1){
		cout<<"! "<<s<<endl;
		return 0;
	}
	cout<<"? 2 "<<n<<endl;
	for(int i=1;i<=(n-1)*n/2;i++)
		cin>>s,sort(s.begin(),s.end()),ms.erase(ms.find(s));
	for(auto i=ms.begin();i!=ms.end();i++)
		ans.push_back(*i);
	sort(ans.begin(),ans.end(),[](string a,string b){return a.size()<b.size();});
	cout<<"! ";
	for(int i=0;i<ans.size();i++){
		for(int j=97;j<124;j++)
			cur[j]=0;
		for(int j=0;j<ans[i].size();j++)
			cur[ans[i][j]]++;
		for(int j=97;j<124;j++)
			if(cnt[j]!=cur[j])
				cout<<(char)j,cnt[j]=cur[j];
	}
	cout<<endl;
}