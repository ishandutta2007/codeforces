#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string c;
	getline(cin,c);
	vector<int> b;
	int i;
	b.push_back(1);
	int p = 1;
	int n = 0;
	for(i = 0; i < c.size(); i++){
		if(c[i] == '='){
			break;
		} else if(c[i] == '+'){
			b.push_back(1);
			p++;
		} else if(c[i] == '-'){
			b.push_back(-1);
			n++;
		}
	}
	int k = 0;
	for(; i < c.size(); i++){
		if(c[i] >= '0' && c[i] <= '9'){
			k *= 10;
			k += (c[i]-'0');
		}
	}
	if(p*k-n*1 < k || 1*p-n*k > k){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	int d = p*k-n*1-k;
	for(int q = 0; q < b.size(); q++){
		if(b[q] == 1){
			if(q >= 1){
				cout << " + ";
			}
			cout << k-min(d,k-1);
			d -= (min(d,k-1));
		} else {
			if(q >= 1){
				cout << " - ";
			}
			cout << 1+min(d,k-1);
			d -= (min(d,k-1));
		}
	}
	cout << " = " << k << endl;
}