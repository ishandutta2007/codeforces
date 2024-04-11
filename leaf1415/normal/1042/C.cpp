#include <iostream>
#include <vector>
#define inf 1e9+5

using namespace std;

int n;
int a[200005];
bool del[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] < 0) cnt++;
	}
	
	if(cnt % 2){
		int mn = inf, mn_i;
		for(int i = 1; i <= n; i++){
			if(a[i] < 0 && mn > -a[i]){
				mn = -a[i];
				mn_i = i;
			}
		}
		del[mn_i] = true;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) del[i] = true;
	}
	
	bool flag = false;
	for(int i = 1; i <= n; i++){
		if(!del[i]){
			flag = true;
			break;
		}
	}
	if(!flag){
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				del[i] = false;
				break;
			}
		}
	}
	
	vector<int> rvec, dvec;
	for(int i = 1; i <= n; i++){
		if(del[i]) dvec.push_back(i);
		else rvec.push_back(i);
	}
	
	for(int i = 0; i < (int)dvec.size()-1; i++){
		cout << "1 " << dvec[i] << " " << dvec[i+1] << endl;
	}
	if(dvec.size()) cout << "2 " << dvec.back() << endl;
	for(int i = 0; i < rvec.size()-1; i++){
		cout << "1 " << rvec[i] << " " << rvec[i+1] << endl;
	}
	
	return 0;
}