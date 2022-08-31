//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
//(x.a*(y.b-x.b)+y.a*(z.b-x.b)+z.a*(x.b-y.b))/2
llo n;
//llo aa[6001][6001];
llo co[2][2];
pair<llo,llo> it[6001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i].a>>it[i].b;
		it[i].a/=2;
		it[i].b/=2;
		co[it[i].a%2][it[i].b%2]++;
	}
	llo ans=0;
	for(llo i=0;i<2;i++){
		for(llo j=0;j<2;j++){
			if(co[i][j]>=3){
				llo cur=co[i][j]*(co[i][j]-1)*(co[i][j]-2);
				cur/=6;
				ans+=cur;

			}

			if(co[i][j]>=2){
				//if(co[1-i][1-j]>=1){
					llo cur=co[i][j]*(co[i][j]-1);
					cur/=2;
					cur*=(n-co[i][j]);
					ans+=cur;
				//}
			}

		}
	}
	cout<<ans<<endl;/*
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			if(i!=j){
				aa[i][j]=__gcd(abs(it[i].a-it[j].a),abs(it[i].b-it[j].b));
			}
			cout<<aa[i][j]<<",";
			aa[i][j]/=2;
		}
		cout<<endl;

	}
	cout<<endl;
	llo ans=0;
	for(llo i=0;i<n;i++){
		for(llo j=i+1;j<n;j++){
			for(llo k=j+1;k<n;k++){
				if((aa[i][j]+aa[j][k]+aa[i][k])%2==0){
					ans++;
				}
			}
		}
	}*/
	//cout<<ans<<endl;
 
 

 
 
 
	return 0;
}