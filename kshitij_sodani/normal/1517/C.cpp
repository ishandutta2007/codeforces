//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int it[501];
int ans[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	for(int i=1;i<=n;i++){
		pair<int,int> cur={i-1,i-1};
		for(int j=0;j<it[i-1];j++){
			ans[cur.a][cur.b]=it[i-1];
			if(j+1<it[i-1]){
				if(cur.b>0){
					if(ans[cur.a][cur.b-1]==0){
						cur.b--;
						continue;
					}
				}
				cur.a++;
			}
		}
	}

for(int i=0;i<n;i++){
	for(int j=0;j<=i;j++){
		cout<<ans[i][j]<<" ";
	}
	cout<<endl;
}
 
	return 0;
}