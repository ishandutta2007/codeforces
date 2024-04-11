#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[555][555];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	dp[0][0]=1;
	for (int i=0;i<n;i++){
		int c;
		cin>>c;
		for (int j=k-c;j>=0;j--){
			for (int a=0;a<=k;a++){
				if (dp[j][a]){
					dp[j+c][a]=1;
					if (a+c<=k) dp[j+c][a+c]=1;
				}
			}
		}
	}
	vector<int> v;
	for (int i=0;i<=k;i++){
		if (dp[k][i]) v.push_back(i);
	}
	cout<<v.size()<<endl;
	for (int vv:v){
		cout<<vv<<" ";
	}
	cout<<endl;
}