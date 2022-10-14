#include<bits/stdc++.h>
#define c(x) ((char)(x+97))
using namespace std;
int const N=33;
int t,n,cnt[N];
string s,p;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(cnt,0,sizeof cnt),cin>>s,n=s.size();
		sort(s.begin(),s.end()),p=s;
		p.erase(unique(p.begin(),p.end()),p.end());
		for(char i:s)cnt[i-97]++;
		int flg=0,t=0;
		for(int i=0;i<26;i++)
			if(cnt[i]==n)
				flg=1,cout<<s<<"\n";
		for(int i=0,t=0;!flg&&i<26;t+=cnt[i++])
			if(cnt[i]==1)
				flg=1,s.erase(s.begin()+s.find(i+97)),
				cout<<c(i)+s<<"\n";
		if(flg)continue;
		int a=p[0]-97;
		if(cnt[a]*2-2<=n){
			cout<<c(a)<<c(a),cnt[a]-=2;
			for(int i=!a;i<26;i++,i+=i==a)
				while(cnt[i]--){
					cout<<c(i);
					if(cnt[a])cout<<c(a),cnt[a]--;
				}
			cout<<"\n";
		}else if(p.size()==2){
			reverse(s.begin(),s.end());
			swap(s[0],s[cnt[p[1]-97]]);
			cout<<s<<"\n";
		}else{
			int b=p[1]-97,d=p[2]-97;
			cout<<c(a)<<c(b)<<string(cnt[a]-1,c(a))<<c(d);
			cnt[b]--,cnt[d]--,cnt[a]=0;
			for(int i=0;i<26;i++)
				if(cnt[i])cout<<string(cnt[i],c(i));
			cout<<"\n";
		}
	}
}