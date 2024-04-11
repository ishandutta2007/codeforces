#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		if(n == 1){
			cout << "! 1 1" << endl;
			continue;
		}
		cout << "? 1 2" << endl;
		string a;
		cin >> a;
		int c = 1; //max
		int d = 2; //min
		if(a[0] == '<'){
			c = 2;
			d = 1;
		}
		for(int i = 3; i <= n; i+= 2){
			int e = i;
			int f = i+1;
			if(i == n){
				f = i;
			} else {
				cout << "? " << e << " " << f << endl;
				string a;
				cin >> a;
				if(a[0] == '<') swap(e,f);
			}

			cout << "? " << c << " " << e << endl;
			cin >> a;
			if(a[0] == '<') swap(c,e);
			cout << "? " << d << " " << f << endl;
			cin >> a;
			if(a[0] == '>') swap(d,f);

		}
		cout << "! " << d << " " << c << endl;
	}
}