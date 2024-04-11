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
llo t;
pair<llo,llo> it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;

		for(llo i=0;i<n;i++){
			cin>>it[i].a;
			it[i].b=i;
		}
		sort(it,it+n);
		llo ans=0;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<i;j++){
				if(it[i].a*it[j].a>2*n){
					break;
				}
				if(it[i].a*it[j].a==it[i].b+it[j].b+2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}









	return 0;
}