#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;
		
		vector<bool> f(26,false);
		{
			int k;
			cin>>k;
			rep(i,k){
				char c;
				cin>>c;
				f[c-'a'] = true;
			}
		}
		while(s.size()!=0 && f[s.back()-'a']==false){
			s.pop_back();
		}
		if(s.size()==0){
			cout<<0<<endl;
			continue;
		}
		reverse(s.begin(),s.end());
		vector<int> t(s.size());
		t[0] = Inf;
		stack<pair<int,int>> S;
		S.emplace(0,Inf);
		int ans = 0;
		for(int i=1;i<t.size();i++){
			t[i] = S.top().first + 1;
			S.top().first++;
			if(S.top().first==S.top().second)S.pop();
			if(f[s[i]-'a'])S.emplace(0,t[i]);
			ans = max(ans,t[i]);
		}
		cout<<ans<<endl;
	}
	
    return 0;
}