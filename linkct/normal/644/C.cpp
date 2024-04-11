#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#define fi first
#define se second
using namespace std;
typedef unsigned long long int ULL;
const ULL SEED = 233ULL;

int n, cnt;
map <string, set <string> > dict;
map <ULL, vector <string> > ans;

inline int idx(char x){
	if(x >= 'a' && x <= 'z') return x - 'a' + 1;
	return x == '/' ? 27 : 28;
}
int main(){
	int i, j; string website, domain, path; ULL hash;
	map <string, set <string> > :: iterator it;
	set <string> :: iterator it_;
	map <ULL, vector <string> > :: iterator it__;
	cin >> n;
	for(i = 1; i <= n; ++ i){
		cin >> website;
		domain.clear();
		for(j = 7; j < website.length() && website[j] != '/'; ++ j)
			domain += website[j];
		path.clear();
		for(; j < website.length(); ++ j) path += website[j];
		dict[domain].insert(path);
	}
	for(it = dict.begin(); it != dict.end(); ++ it){
		hash = 0ULL;
		for(it_ = it -> se.begin(); it_ != it -> se.end(); ++ it_){
			for(i = 0; i < it_ -> length(); ++ i)
				hash = hash * SEED + idx((*it_)[i]);
			hash = hash * SEED + 29ULL;
		}
		ans[hash].push_back(it -> fi);
	}
	for(it__ = ans.begin(); it__ != ans.end(); ++ it__)
		if(it__ -> se.size() > 1) ++ cnt;
	cout << cnt << endl;
	for(it__ = ans.begin(); it__ != ans.end(); ++ it__)
		if(it__ -> se.size() > 1){
			for(i = 0; i < int(it__ -> se.size()) - 1; ++ i)
				cout << "http://" << it__ -> se[i] << ' ';
			cout << "http://" << it__ -> se[it__ -> se.size() - 1] << endl;
		}
	return 0;
}