//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo aa[100001];
llo bb[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	priority_queue<llo> ss;
	llo su=0;
	for(llo i=0;i<n;i++){
		cin>>bb[i];
		llo ans=0;
		ss.push(-(aa[i]+su));
		su+=bb[i];
		while(ss.size()){
			llo no=-ss.top();
			if(no<=su){
				ans+=no-(su-bb[i]);
				ss.pop();
			}
			else{
				break;
			}
		}
		ans+=bb[i]*(llo)ss.size();
		cout<<ans<<" ";//endl;
	}
	cout<<endl;
	
	



 
	return 0;
}