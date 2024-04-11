#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<ctime> 
#define LL long long
using namespace std;
string s,ans;
bool isnum(char c){
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int main(){
	int T;scanf("%d",&T);
	long long x,y,z,w,v;
	while(T--){
		cin>>s;
		int k=0;
		for(int i=0;i<s.length()-1;++i)
			if(isnum(s[i])!=isnum(s[i+1]))++k;
		ans="";
		if(k==1){
			x=0;y=0;w=1;
			for(int i=s.length()-1;i>=0;--i){
				if(isnum(s[i])) {
					ans=s[i]+ans;
					continue;
				}
				z=s[i]-'A';
				y=y+z*w;
				y=y+w;
				w=w*(LL)26;
			} 
			ans='R'+ans+'C';
			cout<<ans;
			cout<<y<<endl;
		}
		else{
			x=0;w=1;
			for(int i=s.length()-1;i>=0;--i){
				if(isnum(s[i])) {
					z=s[i]-'0';
					x=x+w*z;
					w=w*(LL)10;
				}
				else break;
			}
			//cout<<x<<endl;
			v=0;w=1;y;
			while(1){
				if(x>=w){
					++v;
					y=x-w;
					w=w*26+1;
				}
				else break;
			}
			x=y;
			//cout<<x<<endl;
			for(int i=1;i<=v;++i){
				z=x%26;
				ans=char(z+'A')+ans;
				x=x/26;
			}
			cout<<ans;
			for(int i=1;i<s.length();++i){
				if(isnum(s[i])) cout<<s[i];
				else {
					cout<<endl;
					break;
				}
			}
		}
	}
	return 0;
}