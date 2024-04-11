#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	int len = s.size();
	int stuff[len];
	if(p == 1){
		cout << "NO" << endl;
		exit(0);
	}
	if(p == 2){
		if(n >= 3){
			cout << "NO" << endl;
			exit(0);
		}
	}
	for(int i = 0; i < len; i++){
		stuff[i] = s[i]-'a';
	}
	for(int i = len-1; i >= 0; i--){
		int k = stuff[i];
		//cout << k << endl;
		for(int j = k+1; j < p; j++){
			if(i <= 0 || j != stuff[i-1]){
				if(i <= 1 || j != stuff[i-2]){
					s[i] = j+'a';
					stuff[i] = j;
					for(int z = i+1; z < len; z++){
						for(int r = 0; r < p; r++){
							//cout << r << endl;
							if(z <= 0 || r != stuff[z-1]){
								if(z <= 1 || r != stuff[z-2]){
									s[z] = r+'a';
									stuff[z] = r;
									//cout << r << endl;
									break;
								}
							}
							if(r == p-1){
								cout << "NO" << endl;
								exit(0);
							}
						}
					}
					cout << s << endl;
					exit(0);
				}
			}

		}

	}
	cout << "NO" << endl;
	exit(0);
}