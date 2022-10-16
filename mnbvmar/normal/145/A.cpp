#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 100005;

int N;
char str1[MaxN], str2[MaxN];

void input(){
	scanf("%s%s", str1, str2);
    N = strlen(str1);
}

int main(){
	input();
    int numFours1 = 0, numFours2 = 0;

    int numMisses = 0;

    for(int i = 0; i < N; i++){
        if(str1[i] == '4') numFours1++;
        if(str2[i] == '4') numFours2++;
        if(str1[i] != str2[i]) numMisses++;
    }

    int result = abs(numFours1-numFours2);
    result += (numMisses-result)/2;

    printf("%d\n", result);
}