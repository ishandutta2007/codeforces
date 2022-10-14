#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k>>s;
		int cnt=0,mx=0;
		for(int i=0;i<k;i++)
			for(int j=i,cur=0;j<n;j+=k)
				if(s[j]^48)cnt++,mx=max(mx,++cur);
				else cur=max(cur-1,0);
		cout<<cnt-mx<<"\n";
	}
}