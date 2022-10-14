#include<bits/stdc++.h>
using namespace std;
int t,n,a[233];
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		for(cin>>n,n=2*n+1;n--&&(cin>>s);)
			for(char i:s)
				a[i]^=1;
		for(int i=1;;i++)
			if(a[i]){
				cout<<(char)i<<"\n",a[i]--;
				break;
			}
	}
}