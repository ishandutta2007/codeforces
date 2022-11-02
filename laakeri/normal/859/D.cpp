#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ld wp[77][77];

ld dp[200][200];
ld pr[200][200];
ld de[200];

ld mv[200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	n=(1<<n);
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			cin>>wp[i][ii];
			wp[i][ii]/=(ld)100;
		}
	}
	for (int i=0;i<n;i++){
		pr[n+i][i]=1;
	}
	for (int i=n-1;i>=1;i--){
		de[i]=max((ld)1, de[i*2]*(ld)2);
		for (int t=0;t<n;t++){
			dp[i][t]=max(mv[i*2]+dp[i*2+1][t], mv[i*2+1]+dp[i*2][t]);
		}
		for (int t1=0;t1<n;t1++){
			for (int t2=0;t2<n;t2++){
				ld ppr=pr[i*2][t1]*pr[i*2+1][t2];
				pr[i][t1]+=ppr*wp[t1][t2];
				pr[i][t2]+=ppr*((ld)1-wp[t1][t2]);
				
// 				cout<<t1<<" "<<t2<<" "<<ppr<<endl;
				
				dp[i][t1]+=de[i]*ppr*wp[t1][t2];
				dp[i][t2]+=de[i]*ppr*((ld)1-wp[t1][t2]);
			}
		}
		
		for (int t=0;t<n;t++){
			mv[i]=max(mv[i], dp[i][t]);
		}
		
// 		cout<<i<<" "<<mv[i]<<endl;
	}
	cout<<setprecision(15)<<mv[1]<<endl;
}