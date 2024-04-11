#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL M;

void input(){
	cin >> N >> M;
}

int tab[55];

int main(){
	input();
	M--;

	int lptr = 0, rptr = N-1;

	for(LL i = N-1; i > 0; i--){
		if(M & (1LL << (i-1))){
			tab[rptr--] = N-i;
		} else {
			tab[lptr++] = N-i;
		}
	}
	tab[lptr] = N;

	for(int i = 0; i < N; i++) cout << tab[i] << " ";
	cout << endl;
}