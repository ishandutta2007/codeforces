//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[200001];
int pre[200001];
int ma[200001];
int ma2[200001];
int mi[200001];
int mi2[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='+'){
				it[i]=1;
			}
			else{
				it[i]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+it[i-1];
		}
		for(int i=1;i<=n;i++){
			ma[i]=max(ma[i-1],pre[i]);
			mi[i]=min(mi[i-1],pre[i]);
		}
		ma2[n]=pre[n];
		mi2[n]=pre[n];
		for(int i=n-1;i>=0;i--){
			ma2[i]=max(ma2[i+1],pre[i]);
			mi2[i]=min(mi2[i+1],pre[i]);
		}
		while(m--){
			int l,r;
			cin>>l>>r;
			
			pair<int,int> cur={mi[l-1],ma[l-1]};
			int cot=pre[l-1];
			cur.a=min(cur.a,cot+mi2[r]-pre[r]);
			cur.b=max(cur.b,cot+ma2[r]-pre[r]);
			cout<<(cur.b-cur.a+1)<<endl;
		}
	}

 
 
	
 
	return 0;
}