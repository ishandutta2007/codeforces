//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
set<llo> cur[101];
//llo ss[100001];
llo tt[100001];
int tree[100001];
void u(int i,int j){
	while(i<=100000){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int ss(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		string t;
		cin>>t;
		for(llo i=0;i<26;i++){
			cur[i].clear();
		}
		for(llo i=0;i<n;i++){
			//ss[i]=s[i]-'a';
			tt[i]=t[i]-'a';
			cur[s[i]-'a'].insert(i);
		}
		llo ans=n*n;
		llo cur2=0;
		for(int i=0;i<=n;i++){
			tree[i]=0;
		}
		for(int i=1;i<=n;i++){
			u(i,1);
		}

		for(llo i=0;i<n;i++){
			
			for(llo j=0;j<tt[i];j++){
				if(cur[j].size()){
					int x=ss(*(cur[j].begin())+1);
					ans=min(ans,cur2+x-1);
				//	ans=min(ans,cur2+(*cur[j].begin()-i));
				}
			}

			if(cur[tt[i]].size()){
				int ind=*cur[tt[i]].begin();
				int x=ss(*cur[tt[i]].begin()+1);
				cur2+=(x-1);
				cur[tt[i]].erase(cur[tt[i]].begin());
				u(ind+1,-1);
			}
			else{
				break;
			}
		}
		if(ans==(n*n)){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}


	}






 
	return 0;
}