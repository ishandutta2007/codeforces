#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000001
set<string> S;
int ans = Inf;

void go(string s,int now){
	if(s.size()==0)return;
	if(S.count(s)){
		ans = min(ans,now);
		return;
	}
	if(now==ans)return;
	if(s.size()==1)return;
	rep(i,s.size()){
		string t = s;
		t.erase(t.begin()+i);
		if(t[0]=='0')continue;
		go(t,now+1);
	}
}

int main(){	

	for(int i=1;i*i<=Inf;i++){
		S.insert(to_string(i*i));
	}
	
	string s;
	cin>>s;
	
	go(s,0);
	
	if(ans==Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	
    return 0;
}