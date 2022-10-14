#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int t,n,k,p[N][27];
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k>>s,s=" "+s;
		if(n%k){
			cout<<"-1\n";
			continue;
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<26;j++)
				p[i][j]=(i?p[i-1][j]:0)+(j+97==s[i]);
		int cnt=0;
		for(int i=0;i<26;i++)
			cnt+=p[n][i]%k;
		if(!cnt){
			cout<<s.substr(1)<<"\n";
			continue;
		}
		string ans;
		for(int i=n-1;i>=0;i--){
			if(s[i+1]==122)
				continue;
			int t=0;
			for(int j=0;j<26;j++)
				t+=(k-p[i][j]%k)%k;
			if((n-i-t)%k||i+t>n)
				continue;
			int flg=-1;
			for(int j=0;j<26&&!~flg;j++)
				if(j>s[i+1]-97&&p[i][j]%k)flg=j;
			if(!~flg&&i+t==n)
				continue;
			if(~flg&&i+t<n)flg=min(flg,s[i+1]-96);
			else if(i+t<n)flg=s[i+1]-96;
			string r=s.substr(1,i);
			r+=flg+97,p[i][flg]++;
			for(int j=0;j<26;j++)
				r+=string((k-p[i][j]%k)%k,j+97);
			r+=string(n-r.size(),97);
			sort(r.begin()+i+1,r.end());
			ans=r;break;
		}
		cout<<ans<<"\n";
	}
}