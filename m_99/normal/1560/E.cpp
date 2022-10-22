#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		int n = s.size();
		vector<bool> f(26,false);
		vector<int> cnt(26,0);
		vector<int> x;
		for(int i=n-1;i>=0;i--){
			int t = s[i]-'a';
			if(!f[t]){
				f[t] = true;
				x.push_back(t);
			}
			cnt[t]++;
		}
	//	cout<<x.size()<<endl;
		bool F = true;
		rep(i,x.size()){
			int tt = x.size() - i;
			if(cnt[x[i]]%tt!=0){
				F = false;
				break;
			}
			cnt[x[i]] /= tt;
		}
		if(!F){
			cout<<-1<<endl;
			continue;
		}
		
		reverse(x.begin(),x.end());
		string temp = "";
		
		{
			int sum = 0;
			rep(i,26)sum += cnt[i];
			temp = s.substr(0,sum);
			s.erase(s.begin(),s.begin()+sum);
		}
		//cout<<temp<<endl;
		string ans = temp;
		rep(i,x.size()){
			
			string t2 = "";
			rep(j,temp.size()){
				if(temp[j]==x[i]+'a')continue;
				t2 += temp[j];
			}
			swap(t2,temp);
			if(temp != s.substr(0,temp.size())){
				F = false;
				break;
			}
			s.erase(s.begin(),s.begin()+temp.size());
			//cout<<s<<endl;
		}
		if(s.size()!=0)F = false;
		
		if(!F)cout<<-1<<endl;
		else{
			cout<<ans<<' ';
			rep(i,x.size())cout<<(char)(x[i]+'a');
			cout<<endl;
		}
	}
	
	return 0;
}