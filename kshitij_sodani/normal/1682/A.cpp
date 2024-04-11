#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		string s;
		cin>>s;
		if(n==2){
			cout<<2<<endl;
			continue;
		}
		int ans=0;
		if(n%2==1){
			ans++;
		}
		int st=1;
		pair<int,int> cur;
		int ok=0;
		for(int i=(n/2)-1;i>=0;i--){
			if(ok==0){
				if(n%2==0){
					cur={i+1,i+1};
				}
				else{
					cur={i+1,i+2};
				}
				ok++;
			}
			else{
				cur.a--;
				cur.b++;
			}
			if(s[cur.a]!=s[cur.b]){
				st=0;
			}
			ans+=st;
		}
		reverse(s.begin(),s.end());
		ok=0;
		st=1;
		for(int i=(n/2)-1;i>=0;i--){
			if(ok==0){
				if(n%2==0){
					cur={i+1,i+1};
				}
				else{
					cur={i+1,i+2};
				}
				ok++;
			}
			else{
				cur.a--;
				cur.b++;
			}
			if(s[cur.a]!=s[cur.b]){
				st=0;
			}
			ans+=st;
		}
		cout<<ans<<endl;

	}











	return 0;
}