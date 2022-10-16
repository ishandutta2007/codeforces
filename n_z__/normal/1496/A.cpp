#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		if(k==0)cout<<"YES"<<endl;
		else if(n<k*2+1)cout<<"NO"<<endl;
		else {
			for(int x=0;x<k;x++)
			if(s[x]!=s[n-x-1]){cout<<"NO"<<endl;goto Nxt;}
			cout<<"YES"<<endl;
		}
		Nxt:;
	}
}