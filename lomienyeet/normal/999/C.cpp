#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	int cnt[26]={0};
	for(int i=0;i<s.length();i++){
		cnt[s[i]-'a']++;
	}
	if(K<=N){
		int sto=0;
		bool flag=false;
		for(int i=0;i<26;i++){
			if(cnt[i]>0){
				for(int j=0;j<s.length();j++){
					if(sto==K){
						flag=true;
						break;
					}
					if(s[j]==(char)i+97){
						s[j]='.';
						sto++;
					}
				}
			}
			if(flag)break;
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]!='.')cout<<s[i];
	}
}
int main(){
	//multitest
	solve();
}