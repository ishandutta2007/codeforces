#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
int arr[110][110];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}
	vector<int> lis;
	for (int i=0;i<m;i++) lis.push_back(i);
	int maxi = 0;
	for (int j=0;j<n-1;j++) {
		vector<pii> vec;
		for (int i=0;i<m;i++) vec.push_back({arr[i][j]-arr[i][n-1],i});
		sort(vec.begin(),vec.end());
		int cnt = 0;
		for (int i=m-1;i>=-1;i--) {
			if (i>=0) cnt += vec[i].first;
			if (i<0||cnt<0) {
				if (maxi<m-1-i) {
					maxi=m-1-i;
					lis.clear();
					for (int k=0;k<=i;k++) lis.push_back(vec[k].second);
				}
				break;
			}
		}
	}
	printf("%d\n",m-maxi);
	for (int &v : lis) printf("%d ",v+1);
	puts("");
	return 0;
}