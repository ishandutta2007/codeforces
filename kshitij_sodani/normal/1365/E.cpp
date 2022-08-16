#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
llo it[501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo ans=0;
	for(llo i=0;i<n;i++){
		ans=max(ans,it[i]);
		for(llo j=i+1;j<n;j++){
			ans=max(ans,it[i]|it[j]);
			for(llo k=j+1;k<n;k++){
				ans=max(ans,(it[i]|it[j])|it[k]);
			}
		}
	}
	cout<<ans<<endl;





	

	return 0;
}