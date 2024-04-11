#include<bits/stdc++.h>
using namespace std;
string a[20];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		for(int x=0;x<n;x++)cin>>a[x];
		for(int x=0;x<m;x++)
		for(char y='a';y<='z';y++){
			s=a[0];
			s[x]=y;
			for(int z=0;z<n;z++){
				int c=0;
				for(int u=0;u<m;u++)
				if(s[u]!=a[z][u])c++;
				if(c>1)goto none;
			}
			cout<<s<<endl;
			goto done;
            none:;
		}
		cout<<-1<<endl;
        done:;
	}
}