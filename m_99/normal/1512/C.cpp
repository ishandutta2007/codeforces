#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b;
		cin>>a>>b;
		
		string s;
		cin>>s;
		
		
		int n = s.size();
		vector<pair<int,int>> p;
		rep(i,n/2){
			int x = i,y = n-1-i;
			if(s[x]=='?'&&s[y]=='?'){
				p.emplace_back(x,y);
			}
			else{
				if(s[x]=='?'){
					if(s[y]=='0')a-=2;
					else b-=2;
					s[x] = s[y];
				}
				else if(s[y]=='?'){
					if(s[x]=='0')a-=2;
					else b-=2;
					s[y] = s[x];
				}
				else{
					
					if(s[x]=='0')a--;
					else b--;
					if(s[y]=='0')a--;
					else b--;
					if(s[x]!=s[y]){
						a = -100;
					}
				}
			}
		}
		
		if(n%2==1){
			int x = n/2;
			if(s[x]=='0')a--;
			else if(s[x]=='1')b--;
			else{
				if(a%2!=0){
					a--;
					s[x] = '0';
				}
				else{
					b--;
					s[x] = '1';
				}
			}
		}
		
		rep(i,p.size()){
			char c;
			if(a>0){
				a-=2;
				c = '0';
			}
			else{
				b-=2;
				c ='1';
			}
			s[p[i].first] = c;
			s[p[i].second] = c;
		}
		if(a==0&&b==0)cout<<s<<endl;
		else cout<<-1<<endl;
		
	}
	
	return 0;
}