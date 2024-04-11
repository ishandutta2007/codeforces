#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxM = 100005;

int N, M;
int day[MaxM], height[MaxM];

void input(){
	scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &day[i], &height[i]);
    }
}

int main(){
	input();

    int maxHeight = 0;
    maxHeight = max(height[0]+day[0]-1, height[M-1]+(N)-day[M-1]);

    for(int i = 0; i < M-1; i++){
        int day1 = day[i],
            day2 = day[i+1],
            h1   = height[i],
            h2   = height[i+1];

        if(abs(h1-h2) > abs(day1-day2)){
            printf("IMPOSSIBLE\n");
            return 0;
        }

        maxHeight = max(maxHeight, max(h1,h2) + ((day2-day1)-abs(h2-h1))/2);
    }

    printf("%d\n", maxHeight);
}