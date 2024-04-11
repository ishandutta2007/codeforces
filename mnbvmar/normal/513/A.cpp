#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int N1, N2;

void input(){
	scanf("%d%d", &N1, &N2);
}

int main(){
	input();
	if(N2 >= N1)
		printf("Second\n");
	else
		printf("First\n");
}