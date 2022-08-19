#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int a[100000];
int b[100000];
int l[100000];
LL answer[100000];
vector<int> roads[100000];
void dfs(int s, int r){
	//cout << r << " " << a[r]+b[r]-s << " " << s << " " << endl;
	if(roads[s].size() == 1){
		answer[r] = 1;
	} else {
		answer[r] = 1;
		for(int i = 0; i < roads[s].size(); i++){
			if(roads[s][i] != r){
				if(answer[roads[s][i]] == 0){
					dfs(a[roads[s][i]]+b[roads[s][i]]-s, roads[s][i]);
				}
				answer[r] += answer[roads[s][i]];
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> a[i] >> b[i] >> l[i];
		a[i]--;
		b[i]--;
		roads[a[i]].push_back(i);
		roads[b[i]].push_back(i);
		answer[i] = 0;
	}
	int leaf = 0;
	for(int i = 0; i < n; i++){
		if(roads[i].size() == 1){
			leaf = i;
			break;
		}
	}
	//cout << leaf << " " <<  a[roads[leaf][0]]+b[roads[leaf][0]]-leaf << endl;
	dfs(a[roads[leaf][0]]+b[roads[leaf][0]]-leaf, roads[leaf][0]);
	double total = 0;
	for(int i = 0; i < n-1; i++){
		double dr = answer[i];
		double dl = l[i];
		double dn = n;
		total += (6.0)*dr*(dn-dr)*dl/dn/(dn-1.0);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		LL road1, w;
		cin >> road1 >> w;
		road1--;
		double dr = answer[road1];
		double dl = l[road1];
		double dn = n;
		double dw = w;
		total -= (6.0)*dr*(dn-dr)*(dl-dw)/dn/(dn-1.0);
		l[road1] = w;
		printf("%.10lf\n", total);
	}
}