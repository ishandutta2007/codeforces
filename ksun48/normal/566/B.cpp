#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int k = 4*n;
	vector<int> b[n];
	vector<int> c[n];
	vector<int> p[n];
	int cur[n]; // cur = next process need to use
	int cnt[n];
	for(int i = 0; i < n; i++) cnt[i] = cur[i] = 0;
	for(int i = 0; i < k; i++){
		int ax, bx, cx;
		cin >> ax >> bx >> cx;
		ax--; bx--; cx--;

		b[ax].push_back(bx);
		c[ax].push_back(cx);
		p[ax].push_back(i+1);
		cnt[bx]++;
		cnt[cx]++;
	}
	for(int i = 0; i < n; i++){
		if(cnt[i] > 9){
			cout << "NO" << endl;
			return 0;
		}
	}
	vector<int> answer;
	set<pair<int,int> > order; //# process, index
	for(int i = 0; i < n; i++){
		order.insert(make_pair(cnt[i], i));
	}
	while(!order.empty()){

		int a1 = (*order.begin()).second;
		order.erase(order.begin());
		if(cur[a1] == 4){
			continue;
		}
		if(cnt[a1] > 9){
			cout << "NO" << endl;
			return 0;
		}
		int b1 = b[a1][cur[a1]];
		int c1 = c[a1][cur[a1]];
		answer.push_back(p[a1][cur[a1]]);

		cur[a1]++;

		order.erase(make_pair(cnt[b1],b1));
		cnt[b1]--;
		if(cur[b1] != 4) order.insert(make_pair(cnt[b1],b1));

		order.erase(make_pair(cnt[c1],c1));
		cnt[c1]--;
		if(cur[c1] != 4) order.insert(make_pair(cnt[c1],c1));

		order.erase(make_pair(cnt[a1],a1));
		cnt[a1]++;
		if(cur[a1] != 4) order.insert(make_pair(cnt[a1],a1));
	}
	cout << "YES" << endl;
	for(int i = answer.size()-1; i >= 0; i--){
		cout << answer[i] << " ";
	}
	cout << endl;

}