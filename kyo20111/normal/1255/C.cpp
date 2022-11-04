#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100100][4],chk[100100],c,d,e,f;
vector<int> v1,v2;
map<pair<int,int>, pair<int,int>> mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-2;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);

	for(int i=1;i<=n-2;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(j == k || k == l || l == j) continue;
					if(mp[{min(a[i][j], a[i][k]), max(a[i][j], a[i][k])}].first) mp[{min(a[i][j], a[i][k]), max(a[i][j], a[i][k])}].second = a[i][l];
					else mp[{min(a[i][j], a[i][k]), max(a[i][j], a[i][k])}].first = a[i][l];
				}
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=0;j<3;j++) chk[a[i][j]]++;
	}

	for(int i=1;i<=n;i++){
		if(chk[i] == 1){
			c = i;
			break;
		}
	}

	for(int i=1;i<=n-2;i++){
		for(int j=0;j<3;j++){
			if(a[i][j] == c){
				d = i;
				swap(a[i][j], a[i][0]);
				break;
			}
		}
	}

	
	for(int i=1;i<=n-2;i++){
		if(d == i) continue;

		for(int j=0;j<3;j++){
			if(a[i][j] == a[d][1]) v1.push_back(i);
			if(a[i][j] == a[d][2]) v2.push_back(i);
		}
	}

	if(v1.size() > v2.size()) swap(v1, v2), swap(a[d][1], a[d][2]);

	e = a[d][1];
	f = a[d][2];
	d = a[d][0];

	for(int i=1;i<=n;i++){
		printf("%d ",d);
		int tmp = f;
		if(mp[{min(e,f), max(e,f)}].first == d) f = mp[{min(e,f), max(e,f)}].second;
		else f = mp[{min(e,f), max(e,f)}].first;
		d = e;
		e = tmp;
	}
}