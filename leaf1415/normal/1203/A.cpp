#include <iostream>

using namespace std;

int Q;
int n;
int p[205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> p[i];
		
		int pos = 0;
		for(int i = 0; i < n; i++){
			if(p[i] == 1){
				pos = i;
				break;
			}
		}
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(p[(pos+i)%n] != i+1) flag = false;
		}
		if(flag){
			cout << "YES" << "\n";
			continue;
		}
		
		flag = true;
		for(int i = 0; i < n; i++){
			if(p[(pos-i+n)%n] != i+1) flag = false;
		}
		if(flag){
			cout << "YES" << "\n";
			continue;
		}
		
		cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}