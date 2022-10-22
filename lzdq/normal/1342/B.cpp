#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
char str[MAXN];
int main(){
	int _; cin>>_;
	while(_--){
		cin>>str;
		int len=strlen(str);
		bool f=1;
		for(int i=1;i<len;i++)
			if(str[i]!=str[i-1]) f=0;
		if(f) cout<<str;
		else for(int i=0;i<len;i++) cout<<10;
		puts("");	
	}
	return 0;
}