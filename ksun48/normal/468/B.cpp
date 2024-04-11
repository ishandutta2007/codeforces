#include<set>
#include<map>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a == b) a = -203958;
	int p[n];
	int rr[n];
	set<int> stuff;
	map<int,int> m;
	for(int i = 0; i < n; i++){
		rr[i] = -1;
		cin >> p[i];
		m[p[i]] = i;
		stuff.insert(p[i]);
	}
	int did = 0;
	while(!stuff.empty()){
		int s = *stuff.begin();
		int ais = 0;
		int bis = 0;
		if(stuff.find(a-s) != stuff.end()){
			ais = 1;
		}
		if(stuff.find(b-s) != stuff.end()){
			bis = 1;
		}
		if(ais == 0 && bis == 0){
			cout << "NO" << endl;
			return 0;
		}
		if(ais == 0){
			rr[m[s]] = 1;
			rr[m[b-s]] = 1;
			stuff.erase(s);
			stuff.erase(b-s);
			did = 1;
			continue;
		}
		if(bis == 0){
			rr[m[s]] = 0;
			rr[m[a-s]] = 0;
			stuff.erase(s);
			stuff.erase(a-s);
			did = 1;
			continue;
		}

		s = *(stuff.rbegin());
		ais = 0;
		bis = 0;
		if(stuff.find(a-s) != stuff.end()){
			ais = 1;
		}
		if(stuff.find(b-s) != stuff.end()){
			bis = 1;
		}
		if(ais == 0 && bis == 0){
			cout << "NO" << endl;
			return 0;
		}
		if(ais == 0){
			rr[m[s]] = 1;
			rr[m[b-s]] = 1;
			stuff.erase(s);
			stuff.erase(b-s);
			did = 1;
			continue;
		}
		if(bis == 0){
			rr[m[s]] = 0;
			rr[m[a-s]] = 0;
			stuff.erase(s);
			stuff.erase(a-s);
			did = 1;
			continue;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		printf("%d ", rr[i]);
	}
	cout << endl;

}