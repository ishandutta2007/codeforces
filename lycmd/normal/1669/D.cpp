#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int t,n;
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>s;
		int flg=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='W')continue;
			int cnt=0,j=i;
			while(j<s.size()&&s[j]!='W')cnt+=s[j]=='B',j++;
			flg&=cnt&&cnt<j-i,i=j-1;
		}
		cout<<(flg?"YES\n":"NO\n");
	}
	return 0;
}