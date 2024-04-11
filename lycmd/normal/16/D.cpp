#include<bits/stdc++.h>
#define f(x) (s[x]-48)
using namespace std;
int n,ans=1,cnt=1;
string pre,s;
int getime(string s){
	if(s.substr(1,10)=="12:00 a.m.")return 0;
	if(s[1]=='1'&&s[2]=='2')s[1]=s[2]='0';
	return(s[7]<'p'?0:43200)+f(1)*36000+f(2)*3600+f(4)*600+f(5)*60;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n,getline(cin,pre),getline(cin,pre),n--;n--;pre=s){
		getline(cin,s);
		int t1=getime(s),t2=getime(pre);
		if(t1==t2){
			cnt++;
			if(cnt>10)cnt=1,ans++;
		}else{
			cnt=1;
			if(t1<t2)ans++;
		}
	}
	cout<<ans<<"\n";
}