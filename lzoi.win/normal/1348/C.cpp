#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int n,k;
int cnt[26];
string ans;
char s[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		for(int i=0;i<26;i++) cnt[i]=0;
		sort(s,s+n);
		for(int i=0;i<n;i++) cnt[s[i]-'a']++;
		for(int i=0;i<k;i++) cnt[s[i]-'a']--;
		if(s[0]!=s[k-1]){
			cout<<s[k-1]<<endl;
			continue;
		}
		ans="";
		ans+=s[0];
		if(s[k]==s[n-1]){
			while(cnt[s[k]-'a']>0)
				cnt[s[k]-'a']-=k,ans+=s[k];
		}else{
			for(int i=k;i<n;i++){
				ans+=s[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}