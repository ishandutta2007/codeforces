#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,cnt[N],cur[N],f[N][N];
multiset<string>ms;
string s,ans;
vector<string>t;
int main(){
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl,cin>>s,cout<<"! "<<s<<endl;
		return 0;
	}
	int m=n/2;
	cout<<"? 1 "<<m<<endl;
	for(int i=1;i<=m*(m+1)/2;i++)
		cin>>s,sort(s.begin(),s.end()),ms.insert(s);
	if(m==1){
		ans=s;
	}else{
		cout<<"? 2 "<<m<<endl;
		for(int i=1;i<=(m-1)*m/2;i++)
			cin>>s,sort(s.begin(),s.end()),ms.erase(ms.find(s));
		for(auto i=ms.begin();i!=ms.end();i++)
			t.push_back(*i);
		sort(t.begin(),t.end(),[](string a,string b){return a.size()<b.size();});
		for(int i=0;i<t.size();i++){
			for(int j=97;j<124;j++)
				cur[j]=0;
			for(int j=0;j<t[i].size();j++)
				cur[t[i][j]]++;
			for(int j=97;j<124;j++)
				if(cnt[j]!=cur[j])
					ans.push_back(j),cnt[j]=cur[j];
		}
	}
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)
			f[s.size()][s[j]]++;
	}
	for(int i=(n-1)/2;i>=0;i--){
		memset(cur,0,sizeof cur);
		for(int j=i;j<n-i-1;j++)
			cur[ans[j]]++;
		for(int j=97;j<124;j++)
			if(f[i+1][j]-f[i][j]>cur[j]){
				ans.push_back(j);break;
			}
	}
	cout<<"! "<<ans<<endl;
}