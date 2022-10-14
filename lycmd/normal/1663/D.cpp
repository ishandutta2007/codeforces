#include<bits/stdc++.h>
using namespace std;
string s;
int x;
int main(){
	cin>>s>>x;
	switch(s[1]){
		case'B':cout<<(x>1999?"NO\n":"YES\n");break;
		case'R':cout<<(x>2799?"NO\n":"YES\n");break;
		case'G':cout<<(x<1200?"NO\n":"YES\n");break;
		default:cout<<"YES\n";break;
	}
}