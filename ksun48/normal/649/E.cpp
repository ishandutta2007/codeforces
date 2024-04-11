#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a;
pair<int,int> c[200000];
int stuff[400000];
map<int,int> r;
int start[500000];
vector<int> end[500000];
int main(){
	cin >> n >> a;
	for(int i = 0; i < n; i++){
		cin >> c[i].first >> c[i].second;
		c[i].second += c[i].first;
		stuff[i] = c[i].first;
		stuff[i+n] = c[i].second;
	}
	sort(stuff,stuff+2*n);
	for(int i = 0; i < 2*n; i++){
		r[stuff[i]] = i+1;
	}
	for(int i = 0; i < n; i++){
		c[i].first = r[c[i].first];
		c[i].second = r[c[i].second];
		end[c[i].first].push_back(i);
	}
	int s = 0; // can't carry a
	int e = n; // can carry a
	while(s+1 < e){
		int m = (s+e)/2;
		for(int i = 0; i < 500000; i++){
			start[i] = 0;
		}
		for(int i = 0; i < n; i++){
			start[c[i].first]++;
			start[c[i].second]--;
			//cout << c[i].first << " " << c[i].second << endl;
		}
		int cur = 0; // need cur <= m;
		int pass = n;
		multiset<pair<int,int> > off;
		for(int i = 0; i < 500000; i++){
			if(start[i] == 0 && end[i].size() == 0) continue;
			//cout << i << " " << start[i] << " " << end[i].size() << endl;
			for(int j = 0; j < end[i].size(); j++){
				off.insert(make_pair(-c[end[i][j]].second,end[i][j]));
			}
			cur += start[i];
			while(cur > m){
				int l = -(*off.begin()).first;
				off.erase(off.begin());
				pass--;
				cur--;
				start[l]++;
			}
		}
		if(pass >= a){
			e = m;
		} else {
			s = m;
		}
	}
	cout << e << endl;
	int fail[n];
	for(int i = 0; i < n; i++){
		fail[i] = 1;
	}
	for(int i = 0; i < 500000; i++){
		start[i] = 0;
	}
	for(int i = 0; i < n; i++){
		start[c[i].first]++;
		start[c[i].second]--;
		//cout << c[i].first << " " << c[i].second << endl;
	}
	int cur = 0; // need cur <= m;
	int pass = n;
	multiset<pair<int,int> > off;
	for(int i = 0; i < 500000; i++){
		if(start[i] == 0 && end[i].size() == 0) continue;
		for(int j = 0; j < end[i].size(); j++){
			off.insert(make_pair(-c[end[i][j]].second,end[i][j]));
		}
		cur += start[i];
		while(cur > e){
			int l = -(*off.begin()).first;
			fail[(*off.begin()).second] = 0;
			off.erase(off.begin());
			pass--;
			cur--;
			start[l]++;
		}
	}
	int used = 0;
	for(int i = 0; i < n; i++){
		if(used == a) break;
		if(fail[i]){
			used++;
			cout << i+1 << " ";
		}
	}
	cout << endl;
}