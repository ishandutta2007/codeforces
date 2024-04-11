#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int t;
int le[1000001];
int re[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>s;
		n=s.size();
		for(int i=0;i<=2*n;i++){
			le[i]=0;
			re[i]=0;
		}
		int cur=n;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				le[cur]++;
				re[cur-1]++;
				cur--;
			}
			else{
				re[cur]++;
				le[cur+1]++;
				cur++;
			}
		}
		cur=n;
		for(int i=0;i<n;i++){
			int ok=1;
			if(le[cur]>0){
				if(le[cur]==1 and re[cur]>0){

				}
				else{
					ok=0;
				}
			}
			if(ok==0){
				le[cur]--;
				re[cur-1]--;
				cur--;
				cout<<"0";
			}
			else{
				re[cur]--;
				le[cur+1]--;
				cur++;
				cout<<"1";
			}
		}
		cout<<endl;




	}


 
 
 
 
	return 0;
}