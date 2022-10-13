#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int N, A=1,B=0;
	cin >> N;
	while(A <= N)  A *= 10;
	A /= 10;
	while(B <= N) B += A;
	cout << B - N <<endl;
	return 0;
}