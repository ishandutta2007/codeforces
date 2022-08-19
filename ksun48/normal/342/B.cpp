#include <iostream>
using namespace std;

int main() {
	int n,m,s,f;
	cin >> n >> m >> s >> f;
	int k = 0;
	int t[m], l[m],r[m];
	for(int i = 0; i < m; i++){
		cin >> t[i] >> l[i] >> r[i];
	}
	int pos = s;
	if(s<f){
		
		for(int time = 1; time <= 2*n+2*m; time++){
			if(k < m && time == t[k]){
				
				if(pos > r[k] || pos < l[k]-1){
					cout << "R";
					pos++;
					if(pos == f){
						cout << endl;
						return 0;
					}
				} else {
					cout << "X";
				}
				k++;
			} else {
				cout << "R";
				pos++;
				if(pos == f){
					cout << endl;
					return 0;
				}				
			}
		}
	}
	if(s>f){
		
		for(int time = 1; time <= 2*n+2*m; time++){
			if(k < m && time == t[k]){
				if(pos > r[k]+1 || pos < l[k]){
					cout << "L";
					pos--;
					if(pos == f){
						cout << endl;
						return 0;
					}
				} else {
					cout << "X";
				}
				k++;
			} else{
				cout << "L";
				pos--;
				if(pos == f){
					cout << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}