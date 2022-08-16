//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo n;
llo vis[5001];
pair<llo,llo> it[5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i].a>>it[i].b;
	}
	cout<<1<<" ";
	vis[0]=1;
	llo cur=0;
	for(llo i=0;i<n-1;i++){
		llo ma=0;
		llo ind=-1;
		for(llo j=0;j<n;j++){
			if(vis[j]==0){
				llo dis=(it[j].a-it[cur].a)*(it[j].a-it[cur].a);
				dis+=(it[j].b-it[cur].b)*(it[j].b-it[cur].b);
				if(dis>ma){
					ma=dis;
					ind=j;
				}
			}
		}
		cout<<ind+1<<" ";
		vis[ind]=1;
		cur=ind;
	}
	cout<<endl;











 
	return 0;
}