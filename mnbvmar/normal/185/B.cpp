#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int S, tab[3];

void input(){
	cin >> S >> tab[0] >> tab[1] >> tab[2];
}

int main(){
	input();

	if(tab[0] == 0 && tab[1] == 0 && tab[2] == 0){
		printf("0.0 0.0 0.0\n");
		return 0;
	}

	long double sum = 0;
	for(int i = 0; i < 3; i++){
		if(tab[i] != 0)
			sum += tab[i];
	}

	cout << fixed << setprecision(20);

	for(int i = 0; i < 3; i++){
		if(tab[i] == 0)
			cout << 0. << " ";
		else
			cout << S * tab[i] / sum << " ";
	}
	cout << endl;
}