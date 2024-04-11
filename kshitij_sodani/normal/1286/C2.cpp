
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 
int n;
vector<int> co;
vector<int> kk[101];
vector<int> tt;
int cot[101][26];
int pre[101][26];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl;
		string s;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	int nn=n;
	vector<int> ans;
	n/=2;
	for(int i=0;i<26;i++){
		co.pb(0);
	}
	if(n==1){
		cout<<"? 1 1"<<endl;
		string s;
		cin>>s;
		ans.pb(s[0]-'a');
	}
	else{
		
		cout<<"? 1 "<<n<<endl;
		map<vector<int>,int> ss;
		for(int i=0;i<(n*(n+1))/2;i++){
			string s;
			cin>>s;
			for(int j=0;j<26;j++){
				co[j]=0;
			}
			for(int j=0;j<s.size();j++){
				co[s[j]-'a']++;
			}
			ss[co]++;
		}
		cout<<"? 1 "<<n-1<<endl;
		for(int i=0;i<(n*(n-1))/2;i++){
			string s;
			cin>>s;
			for(int j=0;j<26;j++){
				co[j]=0;
			}
			for(int j=0;j<s.size();j++){
				co[s[j]-'a']++;
			}
			ss[co]--;
		}
		for(int i=0;i<26;i++){
			kk[0].pb(0);
		}
		for(auto j:ss){
			if(j.b>0){
				int su=0;
				for(int i=0;i<26;i++){
					su+=j.a[i];
				}
				kk[su]=j.a;
			}
		}
		
		//string s="abcdefghijklmnopqrstuvwxyz";
		for(int j=1;j<=n;j++){
			for(int k=0;k<26;k++){
				if(kk[j][k]>kk[j-1][k]){
					ans.pb(k);
				}
			}
		}
		reverse(ans.begin(),ans.end());
	}
	cout<<"? "<<1<<" "<<nn<<endl;
	string mm;
	for(int j=0;j<(nn*(nn+1))/2;j++){
		string s;
		cin>>s;
	/*	if(s.size()==nn){
			for(int jj=0;jj<26;jj++){
				co[j]=0;
			}
			for(int j=0;j<s.size();j++){
				co[s[j]-'a']++;
			}
		}*/
		for(int jj=0;jj<s.size();jj++){
			//cout<<s.size()<<",,"<<s[j]-'a'<<endl;
			cot[s.size()][s[jj]-'a']++;
		}
	}
/*	for(int i=1;i<=nn;i++){
		for(int j=0;j<3;j++){
			cout<<cot[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;*/
	for(int k=0;k<26;k++){
		for(int j=0;j<=nn/2;j++){
			//cot[j+1][k]-cot[j][k] number of k characters in j+1 to n-j
			int xx=cot[j+1][k]-cot[j][k];
			for(int i=j;i<ans.size();i++){
				if(ans[i]==k){
					xx-=1;
				}
			}
			pre[nn-j-1][k]=xx;
			/*if(xx>0){
				cout<<n-j-1<<",,"<<k<<endl;
			}*/
		}
	}
	for(int j=n;j<nn;j++){
		ans.pb(-1);
	}
	for(int j=n;j<nn;j++){
		for(int k=0;k<26;k++){
			if(pre[j][k]>pre[j-1][k]){
				ans[j]=k;
			}
		}
		/*if(ans[j]==-1){
			while(true){
				continue;
			}
		}*/
	}
	/*for(auto j:ans){
		cout<<j<<",";
	}
	cout<<endl;*/
	string s="abcdefghijklmnopqrstuvwxyz";
	cout<<"! ";
	for(int i=0;i<nn;i++){
		cout<<s[ans[i]];
	}
	cout<<endl;




	return 0;
}