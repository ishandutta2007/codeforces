#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo ans=1e18;
	for(llo i=0;i<n;i++){
		llo cur=0;
		llo su=0;
		for(llo j=i-1;j>=0;j--){
			//aa[j]*x<cur
			if(cur>=1){
				llo zz=((cur-1)/it[j]);
				su+=abs(zz);
				cur=zz*it[j];
			}
			else{
				if((abs(cur-1))%it[j]==0){
					llo zz=(abs(cur-1)/it[j]);
					zz=-zz;
					su+=abs(zz);
					cur=zz*it[j];
				}
				else{
					llo zz=((abs(cur-1)+it[j]-1)/it[j]);
					zz=-zz;
					su+=abs(zz);
					cur=zz*it[j];
				}
			}
		}
		cur=0;
		for(llo j=i+1;j<n;j++){
			//aa[j]*x>cur
			if(cur>=1){
				llo zz=((cur-1)/it[j]);
				su+=abs(zz);
				cur=zz*it[j];
			}
			else{
				if((abs(cur-1))%it[j]==0){
					llo zz=(abs(cur-1)/it[j]);
					zz=-zz;
					su+=abs(zz);
					cur=zz*it[j];
				}
				else{
					llo zz=((abs(cur-1)+it[j]-1)/it[j]);
					zz=-zz;
					su+=abs(zz);
					cur=zz*it[j];
				}
			}
		}
		ans=min(ans,su);
	}
	cout<<ans<<endl;








	return 0;
}