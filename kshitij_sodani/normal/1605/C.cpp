//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
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
		
		int ans=-1;
		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1] and s[i]=='a'){
				ans=2;
			}
		}
		if(ans==-1){
			for(int i=0;i<n-2;i++){
				if(s[i]==s[i+2] and s[i]=='a'){
					if((s[i+1]-'a')!=0){
						ans=3;
					}
				}	
			}
		}
		if(ans==-1){
			for(int i=0;i<n-3;i++){
				if(s[i]=='a' and s[i+3]=='a'){
					if(s[i+1]=='b' and s[i+2]=='c'){
						ans=4;
					}
					if(s[i+1]=='c' and s[i+2]=='b'){
						ans=4;
					}
				}
			}
			if(ans==-1){
				for(int i=0;i<n-6;i++){
					if(s[i]=='a' and s[i]==s[i+3] and s[i+3]==s[i+6]){
						if(s[i+1]==s[i+2] and s[i+1]!='a'){
							if(s[i+4]==s[i+5] and s[i+4]!='a'){
								if(s[i+1]!=s[i+4]){
									ans=7;
								}
							}
						}
					}
				}
			}
			/*vector<int> it;
			for(int i=0;i<n;i++){
				it.pb(s[i]-'a'+1);
			}
			int ind=0;
			int le=-1;
			int re=-1;
			ans=n+1;
			int i=n-1;
			while(i>=0){
				if(it[i]==1){
					if(i+2<n){
						if(it[i+1]==it[i+2]){
							if(it[i+1]==2){
								if(re>=0){
									ans=min(ans,re-i+1);
								}
							}
							else if(it[i+1]==3){
								if(le>=0){
									ans=min(ans,le-i+1);
								}
							}
						}
					}
				}
			
				if(i>=2){
									
					if(it[i]==1){
						if(it[i-1]==it[i-2] and it[i-1]>1){
							if(it[i-1]==2){
								if(i>=3){
									if(it[i-3]==1 and re>=0){
										ans=min(ans,re-(i-3)+1);
									}
								}
								le=i;
								i-=3;
								re=-1;
								continue;
							}
							else if(it[i-1]==3){
								if(i>=3){
									if(it[i-3]==1 and le>=0){
										ans=min(ans,le-(i-3)+1);
									}
								}
								re=i;
								i-=3;
								le=-1;
								continue;
							}
						}
						else if(it[i-1]+it[i-2]==5){
							i-=3;
							continue;
						}
						else{

						}
					}
				}
				le=-1;
				re=-1;
				i--;
			}
			if(ans>n){
				ans=-1;
			}*/
			
		}
		cout<<ans<<endl;
	}


 
	return 0;
}