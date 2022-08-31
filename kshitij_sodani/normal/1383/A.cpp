
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int val[100001];
int par[100001];
int ss[1000001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		string t;
		cin>>s>>t;
		for(int i=0;i<20;i++){
			par[i]=i;
			ss[i]=1;
		}
	
		int st=1;
		for(int i=0;i<n;i++){
			int x=s[i]-'a';
			int y=t[i]-'a';
			if(x>y){
				st=0;
			}
			int xx=find(x);
			int yy=find(y);
			if(xx!=yy){
				par[xx]=yy;
				ss[yy]+=ss[xx];
			}
		//	cout<<x<<":"<<y<<endl;
			/*if(val[x]==-1){
				val[x]=y;
			}
			if(val[x]!=y){
				st=0;
			}*/
		}
		/*int ans=0;
		for(int i=0;i<20;i++){
			if(val[i]!=-1){
				if(val[i]!=i){
					ans+=1;
				}
			}
		}*/
		if(st==0){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<20;i++){
			if(par[i]==i){
			//	cout<<i<<":";
				ans+=ss[i]-1;
			}
		}
	//	cout<<endl;
		cout<<ans<<endl;


	}



	return 0;
}