//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo ans=0;
	for(llo i=0;i<n-1;i+=2){
		ans+=min(it[i],it[i+1]);
	}
	for(llo i=0;i<n;i++){
		if(i%2==1){
			it[i]=-it[i];
		}
	}
	for(llo i=1;i<n;i+=2){
		llo su=0;
		llo ma=0;
		for(llo j=i;j<n-1;j+=1){
			su+=it[j];
			ma=min(ma,su);
			if((j+1)%2==1){
				llo le=it[i-1];
				llo re=abs(it[j+1]);
				llo ma2=min(ma+1,su);
				le--;
				re--;
				llo su2=su;
				if(ma2<0){
					le-=abs(ma2);
					su2=su+abs(ma2);
					if(le<0){
						continue;
					}
				}
				/*if(i==1 and j==2){
					cout<<le<<":"<<re<<endl;
					cout<<ma2<<":"<<su<<endl;
				}*/
			//	if(le>=su2){
					llo cur=min(re-su2,le)+1;
					ans+=max(cur,(llo)0);
				//}
			}
		}
	}
	cout<<ans<<endl;

 
 
 
	return 0;
}