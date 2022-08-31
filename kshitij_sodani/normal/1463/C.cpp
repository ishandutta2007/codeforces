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

llo ee[100001];
llo ff[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		pair<llo,llo> aa={0,0};
	//	llo aa=0;//loc
		llo bb=1;//time

		llo ans=0;
		llo tt=1;
		for(llo i=0;i<n;i++){
			cin>>ee[i]>>ff[i];
		}
		for(llo i=0;i<n;i++){
			llo cc,dd;
			cc=ee[i];
			dd=ff[i];
			//cin>>cc>>dd;
			if(cc>=bb){
				bb=cc+abs(dd-aa.b);
				aa.a=aa.b;
				aa.b=dd;
				tt=cc;
				if(i<n-1){
					if(abs(aa.a-dd)+tt>=ee[i] and abs(aa.a-dd)+tt<=ee[i+1]){
						
					}
					else{
						continue;
					}
				}
			//	tt=cc;
				ans++;
				//cout<<i<<":"<<endl;

			}
			else{
			//	cout<<dd<<","<<aa.a<<","<<aa.b<<","<<tt<<endl;
				if(dd>=min(aa.a,aa.b) and dd<=max(aa.a,aa.b)){
					if(i<n-1){
						if(abs(aa.a-dd)+tt>=ee[i] and abs(aa.a-dd)+tt<=ee[i+1]){
							
						}
						else{
							continue;
						}
					}
					if(i==n-1){
						if(abs(aa.a-dd)+tt<ee[i]){
							continue;
						}
					}
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;




	}







 
	return 0;
}