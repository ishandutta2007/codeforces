#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool check(int n,int k){
	if((n+1)/2 >= k)return true;
	return false;
}


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		int n = s.size();
		
		vector<int> cnt(26,0);
		rep(i,n){
			cnt[s[i]-'a']++;
		}
		{
			bool f = false;
			rep(i,26){
				if(cnt[i]==1){
					f = true;
					string ans(1,'a' + i);
					rep(j,n){
						if(s[j] != 'a'+i){
							ans += s[j];
						}
					}
					sort(ans.begin()+1,ans.end());
					cout<<ans<<endl;
					break;
				}
			}
			if(f)continue;
		}
		
		sort(s.begin(),s.end());
		if(s[0]==s.back()){
			cout<<s<<endl;
			continue;
		}
		
		rep(i,26){
			rep(j,26){
				if(cnt[i]==0||cnt[j]==0)continue;
				
				if(i!=j){
					string ans(1,'a'+i);
					ans += 'a'+j;
					cnt[i]--;
					cnt[j]--;
					string temp = "";
					rep(k,26){
						if(i==k||j==k)continue;
						rep(l,cnt[k])temp += 'a' + k;
					}
					
					if(temp==""){
						rep(k,cnt[j])ans += 'a'+j;
						rep(k,cnt[i])ans += 'a'+i;
					}
					else{
						rep(k,cnt[i])ans += 'a'+i;
						ans += temp[0];
						temp.erase(temp.begin());
						rep(k,cnt[j])ans += 'a'+j;
						rep(k,temp.size())ans += temp[k];
					}
					
					cout<<ans<<endl;
					goto L;
				}
				else{
					if(!check(n-3,cnt[i]-2))continue;
					cnt[i] -= 2;
					string ans(2,'a'+i);
					
					while(ans.size()!=n){
						rep(j,26){
							if(cnt[j]==0)continue;
							if(i==j){
								if(ans.back()=='a'+i)continue;
								cnt[j]--;
								ans += 'a'+j;
								break;
							}
							else{
								if(check(n-(ans.size()+1),cnt[i])){
									ans += 'a'+j;
									cnt[j]--;
									break;
								}
							}
						}
					}
							
					
					
					cout<<ans<<endl;
					goto L;
					
				}
			}
		}
		L:;
		
	}	
	
	return 0;
}