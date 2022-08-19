#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
	pair<int,int> v[8];
	pair<int,int> h[8];
	for(int i = 0; i < 8; i++){
		cin >> v[i].first >> v[i].second;
		h[i].first = v[i].second;
		h[i].second = v[i].first;
	}
	for(int i = 0; i < 8; i++){
		for(int j = i+1; j<8; j++){
			if(v[i].first == v[j].first && v[i].second == v[j].second){
				cout << "ugly" << endl;
				return 0;
			}
		}
	}

	sort(v, v+8);
	sort(h, h+8);
	if(v[0].first == v[1].first && v[1].first == v[2].first && v[2].first != v[3].first && v[3].first == v[4].first
	&&  v[4].first != v[5].first && v[5].first == v[6].first && v[6].first == v[7].first){
	if(h[0].first == h[1].first && h[1].first == h[2].first && h[2].first != h[3].first && h[3].first == h[4].first
	&&  h[4].first != h[5].first && h[5].first == h[6].first && h[6].first == h[7].first){
	cout << "respectable" << endl;
	return 0;
	}
	}
	cout << "ugly" << endl;
}