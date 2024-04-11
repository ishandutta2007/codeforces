#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int T;
	cin>>T;
	
	rep(_,T){
		int n,k;
		scanf("%d %d",&n,&k);
		string s;
		cin>>s;
		
		if(n%k!=0){
			printf("-1\n");
			continue;
		}
		
		int ok = 0;
		vector<int> cnt(26,0);
		rep(i,n){			
			cnt[s[i]-'a']++;
			cnt[s[i]-'a']%=k;
			int need = 0;
			int last = -1;
			rep(j,26){
				if(cnt[j]!=0){
					need += (k - cnt[j]);
					last = j;
				}
			}
			if(i==n-1 && last==-1){
				ok = i+1;
				break;
			}
			if(s[i+1]=='z')continue;
			int remain = n-i-1;
			remain -= need;
			if(last==-1){
				ok = i+1;
			}
			else{
				if(last <= (s[i+1]-'a'))remain -= k;
				if(remain>=0)ok = i+1;
			}
		}
		string ans = "";
		rep(i,ok)ans += s[i];
		if(ans.size()!=n){
			
			for(int i=s[ok]-'a'+1;i<26;i++){
				string t = ans;
				t += 'a'+i;
				cnt.assign(26,0);
				rep(j,t.size()){
					cnt[t[j]-'a']++;
					cnt[t[j]-'a']%=k;
				}
				string y = "";
				for(int j=25;j>=0;j--){
					if(cnt[j]>0){
						rep(x,k-cnt[j])y += ((char)('a' + j));
					}
				}
				
				if(t.size() + y.size() > n)continue;
				while(t.size() + y.size() != n){
					rep(x,k){
						y += 'a';
					}
				}
				reverse(y.begin(),y.end());
				ans = t+y;
			}
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}