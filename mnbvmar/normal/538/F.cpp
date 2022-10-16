#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 200005;
int tab[MaxN];
int N;

void input(){
	scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &tab[i]);
    }
}

int main(){
	input();

    int counter = 0;
    // k = 1
    for(int i = 2; i <= N; i++){
        if(tab[i] < tab[i-1]) counter++;
    }
    printf("%d", counter);

    for(int k = 2; k < N; k++){
        int ptr = 2;

        for(int pnt = 1; (k-1)*(pnt-1) <= N; pnt++){
            int endChildren = ptr+(k-1);
            int prevStart = (k-1)*(pnt-1)+2,
                prevEnd   = (k-1)*pnt + 1;

//            printf("ptr=%d ptrend=%d pstart=%d pend=%d\n", ptr, endChildren,
//                    prevStart, prevEnd);

            for(int i = prevStart; i <= min(ptr-1, prevEnd) && i <= N; i++){
//                printf("pnt=%d --i=%d\n", pnt, i);
                if(tab[i] < tab[pnt]) counter--;
            }
            for(int i = max(ptr, prevEnd+1); i <= endChildren && i <= N; i++){
//                printf("pnt=%d ++i=%d\n", pnt, i);
                if(tab[i] < tab[pnt]) counter++;
            }

            ptr += k;
        }
        printf(" %d", counter);
    }
    printf("\n");
}