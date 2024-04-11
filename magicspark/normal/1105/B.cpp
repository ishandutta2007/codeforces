#include<bits/stdc++.h>
using namespace std;
int n,k;
int st[26]={0};
string s;
int go(int x){
	for(int i=x;i<n-1;i++){
		if(s[i]!=s[i+1]) return i-x+1;
	}
	return n-x;
}
int main(){
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		st[s[i]-'a']+=(go(i)/k);
		i=go(i)+i-1;
	}
	sort(st,st+26);
	cout<<st[25]<<endl;
	return 0;
}