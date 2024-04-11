#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[3000][3000];
pair<int,int > edges[10000000];
int c = 0;
int cc[3000];
int freq[3000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			edges[c].first = a[i][j];
			edges[c].second = i*n+j;
			c++;
		}
		cc[i] = i;
		freq[i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != a[j][i]){
				cout << "NOT MAGIC" << endl;
				return 0;
			}
		}
		if(a[i][i] != 0){
			cout << "NOT MAGIC" << endl;
			return 0;
		}
	}
	sort(edges, edges+c);
	int s = 0;
	while(s < c){
		int e = s;
		while(e+1<c && edges[e+1].first == edges[e].first){
			e++;
		}
		for(int a = s; a <= e; a++){
			int k = edges[a].second/n;
			int l = edges[a].second%n;
			//cout << i << " " << j << endl;
			if(cc[k] != cc[l]){
				int a = min(cc[k], cc[l]);
				int b = max(cc[k], cc[l]);
				for(int q = 0; q < n; q++){
					if(cc[q] == b){
						cc[q] = a;
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			freq[i] = 0;
		}
		for(int i = 0; i < n; i++){
			freq[cc[i]]++;
		}
		int should = 0;
		for(int i = 0; i < n; i++){
			should += freq[i]*freq[i];
		}
		if(should != (e+1)){
			cout << "NOT MAGIC" << endl;
			return 0;
		}
		s = e+1;
	} 
	cout << "MAGIC" << endl;
	return 0;
}