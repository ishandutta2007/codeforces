#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> stuff[1100];
pair<int,pair<int,int> > pt[1000002];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d%d",&pt[i].first,&pt[i].second.first);
		pt[i].second.second = i+1;
	}
	sort(pt, pt+n);
	for(int i = 0; i < n; i++){
		//cout << pt[i].first << " " << pt[i].second << endl;
		stuff[pt[i].second.first / 1000].push_back(pt[i].second.second);
	}
	for(int i = 0; i < 1100; i++){
		if(i % 2 == 0){
			for(int j = 0; j < stuff[i].size(); j++){
				printf("%d ", stuff[i][j]);
			}
		} else {
			for(int j = stuff[i].size()-1; j >= 0; j--){
				printf("%d ", stuff[i][j]);
			}
		}
	}
	printf("\n");

}