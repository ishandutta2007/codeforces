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
llo pre[100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;




	pre[0]=1;
	for(llo i=1;i<=60;i++){
		pre[i]=pre[i-1]*2;
	}
	llo xx=60;
	//cout<<pre[xx]<<endl;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo cot=pre[min(n-1,xx)];
		
		if(cot<k){
			cout<<-1<<endl;
			continue;
		}
		llo cur=0;
		llo le=k;
		while(cur<n){
			llo yy=cur;
			for(llo j=yy;j<n;j++){
				if(j<n-1){
					if(le>pre[min(n-j-2,xx)]){
						le-=(pre[min(n-j-2,xx)]);
						continue;
					}
				}
				for(llo i=j;i>=yy;i--){
					cout<<i+1<<" ";
				}
				cur=j+1;
				break;
			}
		}
		cout<<endl;
	}








 
 
	return 0;
}