#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a1, a2, a3, a4;

void input(){
	scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
}

int main(){
	input();

    if(abs(a3-a4) > 1){
        printf("-1\n");
        return 0;
    }

    int start = (a3 >= a4 ? 4 : 7);

    if(max(a3, a4) > min(a1,a2)){
        printf("-1\n");
        return 0;
    }
    if(start == 4 && a4 == a1) start = 7;    


    string result = start == 4 ? "4" : "7"; //to_string(start);

    int numFours = 0, numSevens = 0;
    if(start == 7) numSevens++; else numFours++;
    int lastSeven = 0;

    while(a3 > 0 || a4 > 0){
        if(*result.rbegin() == '4'){
            result += "7";
            a3--;
            numSevens++;
            lastSeven = (int)result.size() - 1;
        } else {
            result += "4";
            a4--;
            numFours++;
        }
    }

    if(numFours > a1 || numSevens > a2){
        printf("-1\n");
        return 0;
    }

    

    for(int i = 0; i < (int)result.size(); i++){
        if(result[i] == '4'){
            while(numFours < a1){
                printf("4");
                numFours++;
            }
            printf("4");
        } else {
            if(i == lastSeven){
                while(numSevens < a2){
                    printf("7");
                    numSevens++;
                }
            }
            printf("7");
        }
    }
    printf("\n");
}